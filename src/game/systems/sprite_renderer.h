#pragma once

#include <entt/entt.hpp>

#include "../components/sprite.h"
#include "../components/transform.h"

class SpriteRendererSystem
{
  public:
    static void update(entt::registry &registry)
    {
        auto view = registry.view<Sprite, Transform>();
        for (auto entity : view)
        {
            auto &sprite = view.get<Sprite>(entity);
            auto &transform = view.get<Transform>(entity);

            sprite.draw(transform.getPosition(), transform.getSize(), transform.getRotation());
        }
    }
};