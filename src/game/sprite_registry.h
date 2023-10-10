/**
 * @file sprite_registry.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Sprite registry and cache for sprites
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <asw/asw.h>
#include <map>

class SpriteRegistry
{
  public:
    /**
     * @brief Load a sprite from a path, or return a cached version
     *
     * @param path Path to sprite
     * @return asw::Texture Sprite
     */
    static auto loadTexture(const std::string &path) -> asw::Texture
    {
        if (SpriteRegistry::sprites_.find(path) == SpriteRegistry::sprites_.end())
        {
            SpriteRegistry::sprites_[path] = asw::assets::loadTexture(path);
        }

        return SpriteRegistry::sprites_[path];
    }

  private:
    static std::map<std::string, asw::Texture, std::less<>> sprites_;
};
