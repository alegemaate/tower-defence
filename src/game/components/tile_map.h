/**
 * @file tile_map.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Tile map generator
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <asw/asw.h>
#include <entt/entt.hpp>
#include <vector>

#include "./tile.h"
#include "./transform.h"

class TileMap
{
  public:
    /**
     * @brief
     *
     * @param registry
     * @param width
     * @param height
     */
    auto generate(entt::registry &registry, int width, int height) -> void
    {
        clear(registry);

        for (int x = 0; x < width; x += 64)
        {
            for (int y = 0; y < height; y += 64)
            {
                auto tile = registry.create();
                registry.emplace<Transform>(tile, asw::Vec2<float>(x, y), asw::Vec2<float>(64.0, 64.0), 0.0);
                registry.emplace<Tile>(tile, TileType::GRASS_PLOT);
                auto &sprite = registry.emplace<Sprite>(tile, "assets/spritesheet.png",
                                                        Tile::getSpriteIndex(TileType::GRASS_PLOT));

                sprite.setLayer(-64);
                tiles_.push_back(tile);
            }
        }
    }

    /**
     * @brief Clear the tile map
     *
     * @param registry Registry that contains tile entities
     */
    auto clear(entt::registry &registry) -> void
    {
        for (auto tile : tiles_)
        {
            registry.destroy(tile);
        }
        tiles_.clear();
    }

  private:
    std::vector<entt::entity> tiles_;
};