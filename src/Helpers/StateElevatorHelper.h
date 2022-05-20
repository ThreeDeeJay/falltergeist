#pragma once

#include "../Game/Elevator.h"
#include "../ILogger.h"
#include <memory>
#include <string>

namespace Falltergeist {
    namespace Game {
        class Elevator;
    }
    namespace Helpers {
        class StateElevatorHelper {
        public:
            StateElevatorHelper(std::shared_ptr<ILogger>& logger);

            Game::Elevator* getByType(uint32_t type);

        private:
            std::shared_ptr<ILogger> _logger;

            std::vector<Game::Elevator*> _elevators;
        };
    }
}
