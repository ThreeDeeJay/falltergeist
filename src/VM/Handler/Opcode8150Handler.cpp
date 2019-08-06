#include "../../VM/Handler/Opcode8150Handler.h"
#include "../../Logger.h"
#include "../../VM/Script.h"

namespace Falltergeist {
    namespace VM {
        namespace Handler {
            Opcode8150::Opcode8150(std::shared_ptr<VM::Script> script) : OpcodeHandler(script) {
            }

            void Opcode8150::_run() {
                Logger::debug("SCRIPT") << "[8150] [=] int obj_on_screen(void* obj)" << std::endl;
                _script->dataStack()->popObject();
                _script->dataStack()->push(1);
            }
        }
    }
}
