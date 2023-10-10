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

#include "../components/sprite.h"
#include "../components/transform.h"
#include "../components/turret.h"

class TurretPlacementSystem
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

        if (asw::input::wasButtonPressed(asw::input::MouseButton::LEFT))
        {
            auto turret = registry.create();

            registry.emplace<Transform>(turret, mouse_position, Vec2<double>(64.0, 64.0), 0.0);
            registry.emplace<Sprite>(turret, "assets/spritesheet.png",
                                     Vec4<double>(128.0 * 19.0, 128.0 * 10.0, 128.0, 128.0), 90.0);
            registry.emplace<Turret>(turret, 10.0, 10.0, 1.0, 1.0);
        }
    }
};