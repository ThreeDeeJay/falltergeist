#pragma once

#include "../../ILogger.h"
#include "../../VM/OpcodeHandler.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            class Opcode8029 : public OpcodeHandler
            {
                public:
                    Opcode8029(VM::Script *script, std::shared_ptr<ILogger> logger);

                private:
                    std::shared_ptr<ILogger> logger;
                    void _run() override;
            };

        }
    }
}