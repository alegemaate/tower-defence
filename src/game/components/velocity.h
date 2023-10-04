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

class Velocity
{
  public:
    /**
     * @brief Construct a new Velocity object with velocity
     *
     * @param velocity Velocity
     */
    explicit Velocity(Vec2<double> velocity) : velocity_(velocity)
    {
    }

    /**
     * @brief Construct a new Velocity object with velocity and angular velocity
     *
     * @param velocity Velocity
     * @param angular_velocity Angular velocity
     */
    Velocity(Vec2<double> velocity, double angular_velocity) : velocity_(velocity), angular_velocity_(angular_velocity)
    {
    }

    /**
     * @brief Get the Velocity
     *
     * @return Vec2<double>
     */
    auto getVelocity() const -> Vec2<double>
    {
        return velocity_;
    }

    /**
     * @brief Set the Velocity
     *
     * @param velocity New velocity
     */
    void setVelocity(const Vec2<double> &velocity)
    {
        velocity_ = velocity;
    }

    /**
     * @brief Get the Angular Velocity
     *
     * @return double
     */
    auto getAngularVelocity() const -> double
    {
        return angular_velocity_;
    }

    /**
     * @brief Set the Angular Velocity
     *
     * @param angular_velocity New angular velocity
     */
    void setAngularVelocity(const double &angular_velocity)
    {
        angular_velocity_ = angular_velocity;
    }

  private:
    Vec2<double> velocity_{0.0, 0.0};

    double angular_velocity_{0.0};
};