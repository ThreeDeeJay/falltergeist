#include <type_traits>
#include <memory>
#include <utility>
#include "../Event/Dispatcher.h"
#include "../Event/Keyboard.h"
#include "../Event/Mouse.h"
#include "../Event/State.h"

namespace Falltergeist
{
    namespace Event
    {

        Dispatcher::AbstractTask::AbstractTask(EventTarget* target) : target(target) {}

        template <typename T>
        Dispatcher::Task<T>::Task(EventTarget* target, std::unique_ptr<T> event, Base::Delegate<T*> handler)
            : AbstractTask(target), event(std::move(event)), handler(handler)
        {
            static_assert(std::is_base_of<Event, T>::value, "T should be derived from Event::Event.");
        }

        template <typename T>
        void Dispatcher::Task<T>::perform()
        {
            for (auto& func : handler.functors())
            {
                func(event.get());
                // handler may call stopPropagation() - to stop other handlers from executing
                // also, target may be deleted by any handler, so we should check that on every iteration
                if (event->isHandled() || target == nullptr) {
                    break;
                }
            }
        }

        template<typename T>
        void Dispatcher::scheduleEvent(EventTarget* target, std::unique_ptr<T> eventArg, Base::Delegate<T*> handlerArg)
        {
            _scheduledTasks.emplace_back(std::make_unique<Task<T>>(target, std::move(eventArg), std::move(handlerArg)));
        }

        void Dispatcher::processScheduledEvents()
        {
            while (!_scheduledTasks.empty())
            {
                swap(_tasksInProcess, _scheduledTasks);
                for (auto& task : _tasksInProcess)
                {
                    // after previous tasks this target might already be "dead"
                    if (task->target == nullptr) {
                        continue;
                    }
                    task->perform();
                }
                _tasksInProcess.clear();
            }
        }

        void Dispatcher::blockEventHandlers(EventTarget* eventTarget)
        {
            _scheduledTasks.remove_if([eventTarget](std::unique_ptr<Dispatcher::AbstractTask>& task)
            {
                return (task->target == eventTarget);
            });
            for (auto& task : _tasksInProcess)
            {
                if (task->target == eventTarget)
                {
                    task->target = nullptr;
                }
            }
        }

        // instantiations for all event types..
        template void Dispatcher::scheduleEvent<Event>(EventTarget*, std::unique_ptr<Event>, Base::Delegate<Event*>);
        template void Dispatcher::scheduleEvent<Mouse>(EventTarget*, std::unique_ptr<Mouse>, Base::Delegate<Mouse*>);
        template void Dispatcher::scheduleEvent<Keyboard>(EventTarget*, std::unique_ptr<Keyboard>, Base::Delegate<Keyboard*>);
        template void Dispatcher::scheduleEvent<State>(EventTarget*, std::unique_ptr<State>, Base::Delegate<State*>);
    }
}
