/**
 * @file intro.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Intro state and splash screen
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "../state.h"

#include <asw/util/Timer.h>
#include <entt/entt.hpp>

class IntroState : public State
{
  public:
    /**
     * @brief Construct a new Intro State object
     *
     */
    using State::State;

    /**
     * @brief Initialize state
     *
     */
    void init() override;

    /**
     * @brief Draw state
     *
     */
    void draw() override;

    /**
     * @brief Cleanup state
     *
     */
    void cleanup() override;

    /**
     * @brief Update state
     *
     */
    void update() override;

  private:
    /// @brief Timer to keep track of time of splash
    Timer timer;

    /// @brief Entity registry
    entt::registry registry;
};