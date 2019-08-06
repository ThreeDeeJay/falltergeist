#include "../../VM/Handler/Opcode8123Handler.h"
#include "../../Game/CritterObject.h"
#include "../../Logger.h"
#include "../../VM/Script.h"

namespace Falltergeist {
    namespace VM {
        namespace Handler {
            Opcode8123::Opcode8123(std::shared_ptr<VM::Script> script) : OpcodeHandler(script) {
            }

            void Opcode8123::_run() {
                auto critter = dynamic_cast<Game::CritterObject *>(_script->dataStack()->popObject());
                auto value = critter->poisonLevel();
                _script->dataStack()->push(value);
                Logger::debug("SCRIPT") << "[8123] [+] int value = GetPoison(GameCritterObject* critter)" << std::endl
                                        << "    value = " << value << std::endl;
            }
        }
    }
}
