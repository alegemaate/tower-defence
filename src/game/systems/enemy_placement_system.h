/**
 * @file turret_placement_system.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Manages placement of turrets
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <asw/asw.h>
#include <entt/entt.hpp>

#include "../components/enemy.h"
#include "../components/sprite.h"
#include "../components/transform.h"
#include "../components/velocity.h"

#include "../../util/vec2.h"

class EnemyPlacementSystem
{
  public:
    static auto update(entt::registry &registry) -> void
    {
        const auto mouse_position = Vec2<double>(asw::input::mouse.x, asw::input::mouse.y);
        const auto screen_size = asw::display::getSize();

        // Check if mouse is in bounds
        if (mouse_position.x < 0 || mouse_position.y < 0 || mouse_position.x > screen_size.x ||
            mouse_position.y > screen_size.y)
        {
            return;
        }

        if (asw::input::wasButtonPressed(asw::input::MouseButton::RIGHT))
        {
            auto enemy = registry.create();

            registry.emplace<Transform>(enemy, mouse_position, Vec2<double>(64.0, 64.0), 0.0);
            registry.emplace<Sprite>(enemy, "assets/spritesheet.png",
                                     Vec4<double>(128.0 * 15.0, 128.0 * 10.0, 128.0, 128.0), 90.0);
            registry.emplace<Enemy>(enemy);
            registry.emplace<Velocity>(enemy, Vec2<double>(0.0, 0.1));
        }
    }
};