#include "game.h"

#include <asw/asw.h>

#include "../game/components/sprite.h"
#include "../game/components/tile_map.h"
#include "../game/components/transform.h"
#include "../game/components/turret.h"

#include "../game/systems/enemy_placement_system.h"
#include "../game/systems/physics_system.h"
#include "../game/systems/positioning_system.h"
#include "../game/systems/shooting_system.h"
#include "../game/systems/sprite_renderer.h"
#include "../game/systems/turret_placement_system.h"
#include "../util/vec2.h"

const double TILE_WIDTH = 128;
const double TILE_HEIGHT = 128;

void GameState::init()
{

    // Add tile map
    auto tile_map = registry_.create();
    registry_.emplace<TileMap>(tile_map);
    registry_.get<TileMap>(tile_map).generate(registry_, 1024, 1024);
}

void GameState::update()
{
    // Pass
}

void GameState::draw()
{
    asw::draw::clearColor(asw::util::makeColor(255, 255, 255));

    SpriteRendererSystem::update(registry_);
    PositioningSystem::update(registry_, 1.0);
    ShootingSystem::update(registry_, 1.0);
    PhysicsSystem::update(registry_, 1.0);
    TurretPlacementSystem::update(registry_);
    EnemyPlacementSystem::update(registry_);
}

void GameState::cleanup()
{
    // Pass
}