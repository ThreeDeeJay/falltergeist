#pragma once

#include "../../VM/IFalloutOpcode.h"

namespace Falltergeist {
    namespace VM {
        namespace Handler {
            class Opcode8152 : virtual public IFalloutOpcode {
            public:
                Opcode8152(std::shared_ptr<VM::Script> script);;

            private:
                void _run() override;
            };
        }
    }
}
