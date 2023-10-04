/**
 * @file physics_system.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Update physics of transforms
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <entt/entt.hpp>

#include "../components/transform.h"
#include "../components/velocity.h"

class PhysicsSystem
{
  public:
    static auto update(entt::registry &registry, float delta) -> void
    {
        auto view = registry.view<Transform, Velocity>();
        for (auto entity : view)
        {
            auto &transform = view.get<Transform>(entity);
            auto &velocity = view.get<Velocity>(entity);

            // Move transform
            transform.setPosition(transform.getPosition() + velocity.getVelocity() * delta);
            transform.setRotation(transform.getRotation() + velocity.getAngularVelocity() * delta);
        }
    }
};