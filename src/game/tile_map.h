/**
 * @file tile_map.h
 * @author Allan Legemaate (alegemaate@gmail.com)
 * @brief TileMap implementation
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <vector>

class TileMap
{
  public:
    /**
     * @brief Construct a new Tile Map object
     *
     */
    TileMap() = default;

    /**
     * @brief Initialize the tile map dimensions
     *
     * @param width Width of the map in tiles
     * @param height Height of the map in tiles
     * @param tileWidth Width of an individual tile
     * @param tileHeight Height of an individual tile
     */
    void init(int width, int height, int tileWidth, int tileHeight)
    {
        width_ = width;
        height_ = height;
        tile_width_ = tileWidth;
        tile_height_ = tileHeight;
    }

    /**
     * @brief Draw tile map to screen
     *
     */
    void draw()
    {
        // Pass
    }

  private:
    /// @brief Width of the map in tiles
    int width_{0};

    /// @brief Height of the map in tiles
    int height_{0};

    /// @brief Width of an individual tile
    int tile_width_{0};

    /// @brief Height of an individual tile
    int tile_height_{0};

    /// @brief Vector of tile ids
    std::vector<int> tiles_;
};