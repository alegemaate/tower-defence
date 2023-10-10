#pragma once

#include <entt/entt.hpp>

#include "../components/sprite.h"
#include "../components/transform.h"

class SpriteRendererSystem
{
  public:
    static void update(entt::registry &registry)
    {
        // Sort by layer
        registry.sort<Sprite>([](const auto &lhs, const auto &rhs) { return lhs.getLayer() < rhs.getLayer(); });

        auto view = registry.view<const Sprite, const Transform>();
        for (auto [_, sprite, transform] : view.each())
        {
            sprite.draw(transform.getPosition(), transform.getSize(), transform.getRotation());
        }
    }
};