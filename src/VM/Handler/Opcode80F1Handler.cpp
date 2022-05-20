#include "../../VM/Handler/Opcode80F1Handler.h"
#include "../../Game/Game.h"
#include "../../State/Location.h"
#include "../../VM/Script.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode80F1::Opcode80F1(VM::Script *script, std::shared_ptr<ILogger> logger) : OpcodeHandler(script)
            {
                this->logger = std::move(logger);
            }

            void Opcode80F1::_run()
            {
                logger->debug() << "[80F1] [=] void rm_timer_event (void* obj)" << std::endl;
                Game::Object *object = _script->dataStack()->popObject();
                auto state = Game::Game::getInstance()->locationState();
                if (state) {
                    state->removeTimerEvent(object);
                }
            }
        }
    }
}


