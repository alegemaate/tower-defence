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

#include "../components/enemy.h"
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
    static void update(entt::registry &registry, float dt)
    {
        auto view = registry.view<Transform, Turret>();
        auto enemy_view = registry.view<Transform, Enemy>();

        for (auto [_entity, transform, turret] : view.each())
        {
            // Find closest enemy
            int closest = turret.range;
            entt::entity closest_entity = entt::null;

            for (auto [enemy_entity, enemy_transform] : enemy_view.each())
            {
                auto distance = (transform.getPosition() - enemy_transform.getPosition()).magnitude();
                if (distance < closest)
                {
                    closest = distance;
                    closest_entity = enemy_entity;
                }
            }

            if (closest_entity == entt::null || closest > turret.range)
            {
                continue;
            }

            auto closest_transform = registry.get<Transform>(closest_entity);

            // Slow movement
            auto desired_rotation = (closest_transform.getCenter() - transform.getCenter()).angle() * (180.0 / M_PI);
            auto delta_rotation = (desired_rotation - transform.getRotation()) / turret.rotation_speed;
            transform.setRotation(transform.getRotation() + delta_rotation);
        }
    }
};