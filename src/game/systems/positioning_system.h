/**
 * @file positioning_behaviour.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Describe how a tower should position itself
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <asw/asw.h>
#include <cmath>
#include <entt/entt.hpp>

#include "../../util/vec2.h"
#include "../components/transform.h"
#include "../components/turret.h"

class PositioningSystem
{
  public:
    /**
     * @brief Update poisitioning of all entities
     *
     * @param registry Entity registry
     * @param dt Time since last update
     */
    static void update(entt::registry &registry, double dt)
    {
        auto view = registry.view<Transform, Turret>();

        for (auto entity : view)
        {
            auto &transform = view.get<Transform>(entity);

            auto mouse_position = Vec2<double>(asw::input::mouse.x, asw::input::mouse.y);
            auto transform_center = transform.getPosition() + transform.getSize() / 2.0;

            // Slow movement
            auto desired_rotation = (mouse_position - transform_center).angle() * (180.0 / M_PI);
            auto delta_rotation = (desired_rotation - transform.getRotation()) / 30.0;
            transform.setRotation(transform.getRotation() + delta_rotation);
        }
    }
};