#include "../UI/AnimationFrame.h"

namespace Falltergeist
{
    namespace UI
    {
        AnimationFrame::AnimationFrame()
        {
        }

        AnimationFrame::~AnimationFrame()
        {
        }

        Point AnimationFrame::position() const
        {
            return _position;
        }

        void AnimationFrame::setPosition(const Point& pos)
        {
            _position = pos;
        }

        unsigned int AnimationFrame::x() const
        {
            return _position.x();
        }

        unsigned int AnimationFrame::y() const
        {
            return _position.y();
        }

        const Size& AnimationFrame::size() const
        {
            return _size;
        }

        void AnimationFrame::setSize(const Size& size)
        {
            _size = size;
        }

        Point AnimationFrame::offset() const
        {
            return _offset;
        }

        void AnimationFrame::setOffset(const Point& ofs)
        {
            _offset = ofs;
        }

        int AnimationFrame::xOffset() const
        {
            return _offset.x();
        }

        int AnimationFrame::yOffset() const
        {
            return _offset.y();
        }

        void AnimationFrame::setDuration(unsigned int duration)
        {
            _duration = duration;
        }

        unsigned int AnimationFrame::duration() const
        {
            return _duration;
        }
    }
}
