#ifndef TILES_H
#define TILES_H

#include <QString>

typedef enum{
    TILE_WALL,
    TILE_FLOOR,
    TILE_HOLE,
    TILE_FINISH
}TileType;

typedef struct{
    QString text;
    QString imagePath;
    TileType tile;
}tile_t;
#endif // TILES_H
