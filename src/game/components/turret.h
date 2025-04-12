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
    double cooldown{1.0};

    /// @brief initial cooldown in seconds
    double initial_cooldown{1.0};

    /// @brief speed in pixels per second
    double speed{1.0};

    /// @brief damage per shot
    double damage{1.0};

    /// @brief range in pixels
    double range{1.0};

    /// @brief rotation speed
    double rotation_speed{1.0};
};