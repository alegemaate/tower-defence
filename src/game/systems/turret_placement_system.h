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
        const auto mouse_position = asw::Vec2<float>(asw::input::mouse.x, asw::input::mouse.y);
        const auto screen_size = asw::display::getSize();

        // Check if mouse is in bounds
        const auto bounds = asw::Quad<float>(0.0F, 0.0F, screen_size.x, screen_size.y);
        if (!bounds.contains(mouse_position))
        {
            return;
        }

        if (asw::input::wasButtonPressed(asw::input::MouseButton::LEFT))
        {
            auto turret = registry.create();

            registry.emplace<Transform>(turret, mouse_position, asw::Vec2<float>(64.0, 64.0), 0.0);
            registry.emplace<Sprite>(turret, "assets/spritesheet.png",
                                     asw::Quad<float>(128.0 * 19.0, 128.0 * 10.0, 128.0, 128.0), 90.0);
            registry.emplace<Turret>(turret, Turret{
                                                 .cooldown = 100.0,
                                                 .initial_cooldown = 100.0,
                                                 .speed = 1.0,
                                                 .damage = 1.0,
                                                 .range = 100.0,
                                                 .rotation_speed = 30.0,
                                             });
        }
    }
};