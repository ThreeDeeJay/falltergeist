#include "../Game/SceneryObject.h"
#include "../UI/TextArea.h"
#include "../VM/Script.h"

namespace Falltergeist
{
    namespace Game
    {
        SceneryObject::SceneryObject() : Object()
        {
            _type = Type::SCENERY;
        }

        void SceneryObject::setSoundId(char soundId)
        {
            this->_soundId = soundId;
        }

        char SceneryObject::soundId() const
        {
            return _soundId;
        }
    }
}
