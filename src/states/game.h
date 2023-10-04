/**
 * @file game.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Main game state
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "../state.h"

#include <entt/entt.hpp>

class GameState : public State
{
  public:
    using State::State;

    void init() override;

    void draw() override;

    void cleanup() override;

    void update() override;

  private:
    entt::registry registry_;
};