/**
 * @file vec4.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Simple Vec4 class
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

template <class T> class Vec4
{
  public:
    /// @brief The x component
    T x;

    /// @brief The y component
    T y;

    /// @brief The z component
    T z;

    /// @brief The w component
    T w;

    /**
     * @brief Construct a new Vec4 object
     * @details Creates a new Vec4 object with the given x and y components
     *
     * @param x - The x component
     * @param y - The y component
     * @param z - The z component
     * @param w - The w component
     */
    Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
    {
    }

    /**
     * @brief Construct a new Vec 2 object
     * @details Creates a new Vec4 object with the x and y components set to 0
     *
     */
    Vec4() : x(0), y(0), z(0), w(0)
    {
    }

    /**
     * @brief Addition assignment operator
     *
     * @param other The other Vec4 object
     * @return Vec4&
     */
    auto operator+=(const Vec4 &other) -> Vec4 &
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    /**
     * @brief Subtraction assignment operator
     *
     * @param other The other Vec4 object
     * @return Vec4&
     */
    auto operator-=(const Vec4 &other) -> Vec4 &
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    /**
     * @brief Multiplication assignment operator
     *
     * @param other The other Vec4 object
     * @return Vec4&
     */
    auto operator*=(const Vec4 &other) -> Vec4 &
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }

    /**
     * @brief Division assignment operator
     *
     * @param other The other Vec4 object
     * @return Vec4&
     */
    auto operator/=(const Vec4 &other) -> Vec4 &
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
        return *this;
    }

    /**
     * @brief Addition operator
     *
     * @param other The other Vec4 object
     * @return Vec4
     */
    auto operator+(const Vec4 &other) const -> Vec4
    {
        return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    /**
     * @brief Subtraction operator
     *
     * @param other The other Vec4 object
     * @return Vec4
     */
    auto operator-(const Vec4 &other) const -> Vec4
    {
        return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    /**
     * @brief Multiplication operator
     *
     * @param other The other Vec4 object
     * @return Vec4
     */
    auto operator*(const Vec4 &other) const -> Vec4
    {
        return Vec4(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    /**
     * @brief Division operator
     *
     * @param other The other Vec4 object
     * @return Vec4
     */
    auto operator/(const Vec4 &other) const -> Vec4
    {
        return Vec4(x / other.x, y / other.y, z / other.z, w / other.w);
    }

    /**
     * @brief Equality operator
     *
     * @param other The other Vec4 object
     * @return Vec4&
     */
    auto operator==(const Vec4 &other) const -> bool
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    /**
     * @brief Add a scalar to the Vec4 object
     *
     * @param scalar The scalar to add
     * @return Vec4&
     */
    auto operator+(const T scalar) const -> Vec4
    {
        return Vec4(x + scalar, y + scalar, z + scalar, w + scalar);
    }

    /**
     * @brief Subtract a scalar from the Vec4 object
     *
     * @param scalar The scalar to subtract
     * @return Vec4
     */
    auto operator-(const T scalar) const -> Vec4
    {
        return Vec4(x - scalar, y - scalar, z - scalar, w - scalar);
    }

    /**
     * @brief Multiply the Vec4 object by a scalar
     *
     * @param scalar The scalar to multiply by
     * @return Vec4
     */
    auto operator*(const T scalar) const -> Vec4
    {
        return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    /**
     * @brief Divide the Vec4 object by a scalar
     *
     * @param scalar The scalar to divide by
     * @return Vec4
     */
    auto operator/(const T scalar) const -> Vec4
    {
        return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    /**
     * @brief Modulo the Vec4 object by a scalar
     *
     * @param scalar The scalar to modulo by
     * @return Vec4
     */
    auto operator%(const T scalar) const -> Vec4
    {
        return Vec4(x % scalar, y % scalar, z % scalar, w % scalar);
    }
};