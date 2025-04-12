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

#include <asw/asw.h>
#include <asw/util/Timer.h>
#include <entt/entt.hpp>

#include "../state.h"

class IntroState : public asw::scene::Scene<States>
{
  public:
    /**
     * @brief Construct a new Intro State object
     *
     */
    using asw::scene::Scene<States>::Scene;

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
     * @brief Update state
     *
     */
    void update(float deltaTime) override;

  private:
    /// @brief Timer to keep track of time of splash
    Timer timer;

    /// @brief Entity registry
    entt::registry registry;
};