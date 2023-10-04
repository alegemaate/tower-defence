/**
 * @file shooting_system.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Control shooting of turrets
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <cmath>
#include <entt/entt.hpp>

#include "../components/bullet.h"
#include "../components/sprite.h"
#include "../components/transform.h"
#include "../components/turret.h"
#include "../components/velocity.h"

class ShootingSystem
{
  public:
    static auto update(entt::registry &registry, float delta) -> void
    {
        auto view = registry.view<Transform, Turret>();
        for (auto entity : view)
        {
            const auto &transform = view.get<Transform>(entity);
            auto &turret = view.get<Turret>(entity);

            // Shoot bullet
            if (turret.getCooldown() <= 0)
            {

                // Calculate vec2 velocity based on rotation of transform and speed of turret
                auto bullet_velocity = Vec2<double>(cos(transform.getRotation() * M_PI / 180.0),
                                                    sin(transform.getRotation() * M_PI / 180.0)) *
                                       turret.getSpeed();

                // Create bullet
                auto bullet = registry.create();
                registry.emplace<Transform>(bullet, transform.getCenter(), Vec2<double>(16.0, 16.0),
                                            transform.getRotation());
                registry.emplace<Velocity>(bullet, bullet_velocity, 1.0);
                registry.emplace<Bullet>(bullet, turret.getDamage());
                registry.emplace<Sprite>(bullet, "assets/intro.png");

                // Reset cooldown
                turret.resetCooldown();
            }
            else
            {
                // Update cooldown
                turret.setCooldown(turret.getCooldown() - delta);
            }
        }
    }
};