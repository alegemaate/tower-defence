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

void GameState::init()
{

    // Add tile map
    auto tile_map = registry_.create();
    registry_.emplace<TileMap>(tile_map);
    registry_.get<TileMap>(tile_map).generate(registry_, 1024, 1024);
}

void GameState::update(float dt)
{
    Scene::update(dt);

    PositioningSystem::update(registry_, dt);
    ShootingSystem::update(registry_, dt);
    PhysicsSystem::update(registry_, dt);
    TurretPlacementSystem::update(registry_);
    EnemyPlacementSystem::update(registry_);
}

void GameState::draw()
{
    asw::draw::clearColor(asw::util::makeColor(255, 255, 255));

    SpriteRendererSystem::update(registry_);
}
