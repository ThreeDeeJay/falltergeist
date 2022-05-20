#pragma once

#include "../Game/SceneryObject.h"
#include "../ILogger.h"

namespace Falltergeist
{
    namespace Event
    {
        class Event;
    }

    namespace Game
    {
        /**
         * Doors. Can be opened, closed, locked and unlocked.
         */
        class DoorSceneryObject : public SceneryObject
        {
            public:
                DoorSceneryObject(std::shared_ptr<ILogger> logger);
                ~DoorSceneryObject() = default;

                bool opened() const;
                void setOpened(bool value);

                bool locked() const;
                void setLocked(bool value);

                bool canWalkThru() const override;

                void use_p_proc(CritterObject* usedBy) override;

                void onOpeningAnimationEnded(UI::AnimationQueue* target);
                void onClosingAnimationEnded(UI::AnimationQueue* target);

            private:
                std::shared_ptr<ILogger> logger;
                bool _opened = false;
                bool _locked = false;
        };
    }
}
