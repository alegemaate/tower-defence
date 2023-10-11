/**
 * @file velocity.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Velocity component
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "../../util/vec2.h"

struct Velocity
{
    /// @brief Velocity
    Vec2<double> velocity{0.0, 0.0};

    /// @brief Angular velocity
    double angular_velocity{0.0};
};