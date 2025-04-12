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

struct Turret
{
    /// @brief cooldown in seconds
    float cooldown{1.0};

    /// @brief initial cooldown in seconds
    float initial_cooldown{1.0};

    /// @brief speed in pixels per second
    float speed{1.0};

    /// @brief damage per shot
    float damage{1.0};

    /// @brief range in pixels
    float range{1.0};

    /// @brief rotation speed
    float rotation_speed{1.0};

    /// @brief has target
    bool has_target{false};
};