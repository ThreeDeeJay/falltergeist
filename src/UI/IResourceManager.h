#pragma once

#include <memory>


namespace Falltergeist
{
    namespace Graphics
    {
        class Sprite;
    }

    namespace UI
    {
        class Image;

        class IResourceManager
        {
            public:
                virtual ~IResourceManager() = default;

                // TODO replace with smart pointer
                virtual Image* getImage(const std::string &filename) = 0;
                virtual std::shared_ptr<Graphics::Sprite> getSprite(const std::string &filename) = 0;
        };
    }
}
