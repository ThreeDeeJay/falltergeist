#pragma once

// Project includes
#include "../../ILogger.h"
#include "../../VM/OpcodeHandler.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            class Opcode8018 : public OpcodeHandler
            {
                public:
                    Opcode8018(VM::Script *script, std::shared_ptr<ILogger> logger);

                private:
                    std::shared_ptr<ILogger> logger;
                    void _run() override;
            };
        }
    }
}
