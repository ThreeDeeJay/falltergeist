#pragma once

#include <memory>
#include "../Event/Handler.h"

namespace Falltergeist
{
    namespace Event
    {
        class Event;
        class Dispatcher;

        class EventTarget
        {
            public:
                EventTarget(Dispatcher* eventDispatcher);
                virtual ~EventTarget();

                /**
                 * Emit given event to Event Dispatcher for delayed processing.
                 */
                template <typename T>
                void emitEvent(std::unique_ptr<T> event, const Base::Delegate<T*>& handler);

            private:
                Dispatcher* _eventDispatcher;
        };
    }
}
