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

#include <asw/asw.h>

struct Velocity
{
    /// @brief Velocity
    asw::Vec2<float> velocity{0.0, 0.0};

    /// @brief Angular velocity
    float angular_velocity{0.0};
};