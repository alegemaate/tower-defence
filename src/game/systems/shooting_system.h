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
    static auto update(entt::registry &registry, float dt) -> void
    {
        auto view = registry.view<Transform, Turret>();
        for (auto entity : view)
        {
            const auto &transform = view.get<Transform>(entity);
            auto &turret = view.get<Turret>(entity);

            // Shoot bullet
            if (turret.cooldown <= 0)
            {

                // Calculate vec2 velocity based on rotation of transform and speed of turret
                auto bullet_velocity = asw::Vec2<float>(std::cos(transform.getRotation() * M_PI / 180.0),
                                                        std::sin(transform.getRotation() * M_PI / 180.0)) *
                                       turret.speed;

                // Create bullet
                auto bullet = registry.create();
                registry.emplace<Transform>(bullet, transform.getCenter() - asw::Vec2<float>(32.0, 32.0),
                                            asw::Vec2<float>(64.0, 64.0), transform.getRotation());
                registry.emplace<Velocity>(bullet, bullet_velocity, 1.0);
                registry.emplace<Bullet>(bullet, turret.damage);
                auto &sprite = registry.emplace<Sprite>(bullet, "assets/spritesheet.png",
                                                        asw::Quad<float>(128.0 * 19.0, 128.0 * 11.0, 128.0, 128.0));
                sprite.setLayer(-16);

                // Reset cooldown
                turret.cooldown = turret.initial_cooldown;
            }
            else
            {
                // Update cooldown
                turret.cooldown = turret.cooldown - dt;
            }
        }
    }
};