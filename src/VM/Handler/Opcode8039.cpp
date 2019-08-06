#include "../../VM/Handler/Opcode8039.h"
#include "../../VM/IFalloutContext.h"
#include "../../VM/IFalloutStack.h"
#include "../../VM/IFalloutValue.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            void Opcode8039::applyTo(std::shared_ptr<Falltergeist::VM::IFalloutContext> context)
            {
                auto bValue = context->dataStack()->pop();
                auto aValue = context->dataStack()->pop();
                context->dataStack()->push(aValue->add(bValue));
            }

            int Opcode8039::number()
            {
                return 0x8039;
            }

            std::string Opcode8039::name()
            {
                return "mixed = op_add(mixed a, mixed b)";
            }

            std::string Opcode8039::notes()
            {
                return "";
            }
        }
    }
}
