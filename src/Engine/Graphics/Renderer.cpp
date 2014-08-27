/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// C++ standard includes

// Falltergeist includes
#include "../../Engine/Graphics/Renderer.h"
#include "../../Engine/Game.h"
#include "../../Engine/UI.h"
#include "../../Engine/Input/Mouse.h"

// Third party includes

namespace Falltergeist
{

Renderer::Renderer(unsigned int width, unsigned int height)
{
    _width = width;
    _height = height;
}

Renderer::~Renderer()
{
}

void Renderer::init()
{
}

void Renderer::beginFrame()
{
    auto game = &Game::getInstance();

    for (auto i = game->ui()->begin(); i != game->ui()->end(); ++i)
    {
        drawTexture((*i)->x(), (*i)->y(), (*i)->texture());
    }

    // Render mouse
    if (game->mouse()->visible())
    {
        drawTexture(game->mouse()->x(), game->mouse()->y(), game->mouse()->texture());
    }
}

void Renderer::endFrame()
{
}

unsigned int Renderer::width()
{
    return _width;
}

unsigned int Renderer::height()
{
    return _height;
}

void Renderer::registerTexture(Texture* texture)
{
}

void Renderer::unregisterTexture(Texture* texture)
{
}

void Renderer::drawTexture(unsigned int x, unsigned int y, Texture* texture)
{
}

}
