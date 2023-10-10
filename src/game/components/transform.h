/**
 * @file transform.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Defines a transform for an entity
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "../../util/vec2.h"

#include <cmath>

class Transform
{
  public:
    /**
     * @brief Construct a new Transform
     *
     * @param position - Position in world space
     * @param size - Size in world space
     * @param rotation - Rotation in radians
     */
    Transform(Vec2<double> position, Vec2<double> size, double rotation = 0.0)
        : position_(position), size_(size), rotation_(rotation)
    {
    }

    /**
     * @brief Get position
     *
     */
    auto getPosition() const -> Vec2<double>
    {
        return position_;
    }

    /**
     * @brief Set position
     *
     */
    void setPosition(const Vec2<double> &position)
    {
        position_ = position;
    }

    /**
     * @brief Get size
     *
     */
    auto getSize() const -> Vec2<double>
    {
        return size_;
    }

    /**
     * @brief Set size
     *
     */
    void setSize(const Vec2<double> &size)
    {
        size_ = size;
    }

    /**
     * @brief Get rotation
     *
     */
    auto getRotation() const -> double
    {
        return rotation_;
    }

    /**
     * @brief Set rotation
     *
     */
    void setRotation(double rotation)
    {

        rotation_ = rotation;
    }

    /**
     * @brief Get center of transform
     *
     */
    auto getCenter() const -> Vec2<double>
    {
        return position_ + size_ / 2.0;
    }

  private:
    /// @brief Position in world space
    Vec2<double> position_{0.0, 0.0};

    /// @brief Size in world space
    Vec2<double> size_{0.0, 0.0};

    /// @brief Rotation in radians
    double rotation_{0.0};
};