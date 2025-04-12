/**
 * @file tile.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief Tile component
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <asw/asw.h>

constexpr int TILE_SIZE = 128;
constexpr int SPRITESHEET_WIDTH = 23;
constexpr int SPRITESHEET_HEIGHT = 14;

enum class TileType
{
    GRASS = 152,
    DIRT = 153,
    STONE = 154,
    GRASS_PLOT = 42,
    DIRT_PLOT = 64,
    STONE_PLOT = 86,
    TREE_LARGE = 126,
    TREE_SMALL = 127,
    BUSH_SMALL = 128,
    TREE_ROUND = 129,
    BUSH_LARGE = 130,
    STONE_SMALL = 131,
    STONE_LARGE = 132,
};

class Tile
{
  public:
    explicit Tile(TileType type) : type_(type)
    {
    }

    auto getType() const -> TileType
    {
        return type_;
    }

    static auto getSpriteIndex(TileType type) -> asw::Quad<float>
    {
        auto x = static_cast<int>(type) % SPRITESHEET_WIDTH;
        auto y = static_cast<int>(type) / SPRITESHEET_WIDTH;

        return asw::Quad<float>(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
    }

  private:
    TileType type_;
};
