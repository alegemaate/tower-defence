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

#include <asw/asw.h>
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
    Transform(asw::Vec2<float> position, asw::Vec2<float> size, float rotation = 0.0F)
        : position_(position), size_(size), rotation_(rotation)
    {
    }

    /**
     * @brief Get position
     *
     */
    auto getPosition() const -> asw::Vec2<float>
    {
        return position_;
    }

    /**
     * @brief Set position
     *
     */
    void setPosition(const asw::Vec2<float> &position)
    {
        position_ = position;
    }

    /**
     * @brief Get size
     *
     */
    auto getSize() const -> asw::Vec2<float>
    {
        return size_;
    }

    /**
     * @brief Set size
     *
     */
    void setSize(const asw::Vec2<float> &size)
    {
        size_ = size;
    }

    /**
     * @brief Get rotation
     *
     */
    auto getRotation() const -> float
    {
        return rotation_;
    }

    /**
     * @brief Set rotation
     *
     */
    void setRotation(float rotation)
    {
        rotation_ = rotation;
    }

    /**
     * @brief Get center of transform
     *
     */
    auto getCenter() const -> asw::Vec2<float>
    {
        return position_ + size_ / 2.0;
    }

  private:
    /// @brief Position in world space
    asw::Vec2<float> position_{0.0, 0.0};

    /// @brief Size in world space
    asw::Vec2<float> size_{0.0, 0.0};

    /// @brief Rotation in radians
    float rotation_{0.0};
};