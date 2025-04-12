/**
 * @file bullet.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Bullet component
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

class Bullet
{
  public:
    Bullet(float damage) : damange(damage)
    {
    }

    auto getDamage() const -> float
    {
        return damange;
    }

  private:
    float damange{1.0f};
};