#pragma once

#include "../Base/Delegate.h"

namespace Falltergeist
{
    namespace Event
    {
        class Event;
        class Mouse;
        class Keyboard;
        class State;

        // TODO: copy-pasting Base::Delegate code instead of using template might improve compilation speed

        using Handler = Base::Delegate<Event*>;
        using MouseHandler = Base::Delegate<Mouse*>;
        using KeyboardHandler = Base::Delegate<Keyboard*>;
        using StateHandler = Base::Delegate<State*>;
    }
}
