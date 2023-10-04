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

#include "../state.h"

/**
 * @brief Init state, used to initialize the game
 */
class InitState : public State
{
  public:
    /**
     * @brief Initialize the init state
     * @param engine
     */
    using State::State;

    /**
     * @brief Initialize the state
     */
    void init() override;

    /**
     * @brief Draw the state
     */
    void draw() override;

    /**
     * @brief Cleanup the state
     */
    void cleanup() override;

    /**
     * @brief Update the state
     */
    void update() override;
};