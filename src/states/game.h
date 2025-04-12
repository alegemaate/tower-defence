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

#include <asw/asw.h>
#include <entt/entt.hpp>

#include "../state.h"

class GameState : public asw::scene::Scene<States>
{
  public:
    using asw::scene::Scene<States>::Scene;

    void init() override;

    void draw() override;

    void update(float dt) override;

  private:
    entt::registry registry_;
};