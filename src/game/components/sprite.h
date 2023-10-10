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

#include "../../util/vec2.h"
#include "../../util/vec4.h"
#include "../sprite_registry.h"

class Sprite
{
  public:
    explicit Sprite(const std::string &path)
    {
        sprite_ = SpriteRegistry::loadTexture(path);

        auto sprite_size = asw::util::getTextureSize(sprite_);
        clip_ = Vec4<double>(0, 0, sprite_size.x, sprite_size.y);
    }

    Sprite(const std::string &path, const Vec4<double> &clip, const double rotation = 0.0)
        : clip_(clip), rotation_(rotation)
    {
        sprite_ = SpriteRegistry::loadTexture(path);
    }

    void draw(const Vec2<double> &position, const Vec2<double> &size, double rotation) const
    {
        asw::draw::stretchSpriteRotateBlit(sprite_, clip_.x, clip_.y, clip_.z, clip_.w, position.x, position.y, size.x,
                                           size.y, rotation + rotation_);
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

    Vec4<double> clip_;

    double rotation_{0.0};

    int layer_{0};
};