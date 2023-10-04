#include "game.h"

#include <asw/asw.h>

#include "../game/components/sprite.h"
#include "../game/components/transform.h"
#include "../game/systems/positioning_system.h"
#include "../game/systems/sprite_renderer.h"
#include "../util/vec2.h"

const double TILE_WIDTH = 128;
const double TILE_HEIGHT = 128;

void GameState::init()
{
    // Create entt sprite
    auto turret = registry_.create();

    // Add sprite component
    registry_.emplace<Sprite>(turret, "assets/spritesheet.png",
                              Vec4<double>(TILE_WIDTH * 19.0, TILE_HEIGHT * 10.0, TILE_WIDTH, TILE_HEIGHT), 90.0);
    registry_.emplace<Transform>(turret, Vec2<double>(100.0, 100.0), Vec2<double>(64.0, 64.0), 45.0);
}

void GameState::update()
{
    // Pass
}

void GameState::draw()
{
    asw::draw::clearColor(asw::util::makeColor(255, 0, 0, 255));

    SpriteRendererSystem::update(registry_);
    PositioningSystem::update(registry_, 0.0);
}

void GameState::cleanup()
{
    // Pass
}