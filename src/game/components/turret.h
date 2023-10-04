/**
 * @file turret.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Turret component
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "../../util/vec2.h"

class Turret
{
  public:
    Turret(double cooldown, double speed, double damage, double range)
        : cooldown_(cooldown), speed_(speed), damage_(damage), range_(range), initial_cooldown_(cooldown)
    {
    }

    auto getCooldown() const -> double
    {
        return cooldown_;
    }

    auto setCooldown(double cooldown) -> void
    {
        cooldown_ = cooldown;
    }

    auto getSpeed() const -> double
    {
        return speed_;
    }

    auto setSpeed(double speed) -> void
    {
        speed_ = speed;
    }

    auto getDamage() const -> double
    {
        return damage_;
    }

    auto setDamage(double damage) -> void
    {
        damage_ = damage;
    }

    auto getRange() const -> double
    {
        return range_;
    }

    auto setRange(double range) -> void
    {
        range_ = range;
    }

    /**
     * @brief Reset cooldown
     *
     */
    auto resetCooldown() -> void
    {
        cooldown_ = initial_cooldown_;
    }

  private:
    double cooldown_{1.0};
    double initial_cooldown_{1.0};
    double speed_{1.0};
    double damage_{1.0};
    double range_{1.0};
};