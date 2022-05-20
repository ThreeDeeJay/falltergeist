#pragma once

#include "../Graphics/Sprite.h"
#include "../UI/Base.h"

namespace Falltergeist
{
    namespace UI
    {
        class Image;

        class ElevatorProgress : public Base
        {
            public:
                ElevatorProgress(const Point& pos = Point(0, 0));

                ElevatorProgress(uint8_t progress, const Point& pos = Point(0, 0));

                uint8_t progress() const;

                void setProgress(uint8_t progress);

                bool opaque(const Point &pos) override;

                void render(bool eggTransparency) override;

            private:
                uint8_t _progress;

                Size _size;

                std::shared_ptr<Graphics::Sprite> _sprite;

                std::vector<SDL_Rect> _rects;
        };
    }
}
