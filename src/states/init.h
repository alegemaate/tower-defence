/**
 * @file init.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Init State Class Header
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <asw/asw.h>

#include "../state.h"

/**
 * @brief Init state, used to initialize the game
 */
class InitState : public asw::scene::Scene<States>
{
  public:
    /**
     * @brief Initialize the init state
     * @param engine
     */
    using asw::scene::Scene<States>::Scene;

    /**
     * @brief Update the state
     */
    void update(float deltaTime) override;
};