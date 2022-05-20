#include "../../VM/Handler/Opcode80A9Handler.h"
#include "../../Game/DudeObject.h"
#include "../../Game/Game.h"
#include "../../State/Location.h"
#include "../../PathFinding/Hexagon.h"
#include "../../PathFinding/HexagonGrid.h"
#include "../../VM/Script.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode80A9::Opcode80A9(VM::Script *script, std::shared_ptr<ILogger> logger) : OpcodeHandler(script)
            {
                this->logger = std::move(logger);
            }

            void Opcode80A9::_run()
            {
                logger->debug()
                        << "[80A9] [+] void override_map_start(int x, int y, int elevation, int orientation)"
                        << std::endl;
                auto dataStack = _script->dataStack();

                auto orientation = dataStack->popInteger();
                auto elevation = dataStack->popInteger();
                auto y = dataStack->popInteger();
                auto x = dataStack->popInteger();
                auto position = y * 200 + x;
                auto game = Game::Game::getInstance();
                auto player = game->player();
                auto hexagon = game->locationState()->hexagonGrid()->at(position);
                Game::Game::getInstance()->locationState()->moveObjectToHexagon(player.get(), hexagon);
                //player->setPosition(position);
                player->setOrientation(orientation);
                player->setElevation(elevation);
                Game::Game::getInstance()->locationState()->centerCameraAtHexagon(player->hexagon());
            }
        }
    }
}
