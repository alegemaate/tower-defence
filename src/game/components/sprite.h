/**
 * @file sprite.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Sprite component
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <asw/asw.h>

#include "../sprite_registry.h"

class Sprite
{
  public:
    explicit Sprite(const std::string &path)
    {
        sprite_ = SpriteRegistry::loadTexture(path);

        auto sprite_size = asw::util::getTextureSize(sprite_);
        clip_ = asw::Quad<float>(0, 0, sprite_size.x, sprite_size.y);
    }

    Sprite(const std::string &path, const asw::Quad<float> &clip, const float rotation = 0.0)
        : clip_(clip), rotation_(rotation)
    {
        sprite_ = SpriteRegistry::loadTexture(path);
    }

    void draw(const asw::Vec2<float> &position, const asw::Vec2<float> &size, float rotation) const
    {
        asw::draw::stretchSpriteRotateBlit(sprite_, clip_, asw::Quad<float>(position, size), rotation + rotation_);
    }

    void setLayer(int layer)
    {
        layer_ = layer;
    }

    int getLayer() const
    {
        return layer_;
    }

  private:
    asw::Texture sprite_;

    asw::Quad<float> clip_;

    float rotation_{0.0F};

    int layer_{0};
};