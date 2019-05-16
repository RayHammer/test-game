#pragma once
#include "Headers.h"

typedef int Tile;

class Level {
public:
    Level();
    ~Level();
    bool loadFromFile(const std::string &path);
    VertexArray &getVertexArray() {
        return bgVA;
    }
private:
    const int TILE_SIZE = 32;
    const int VERTS_IN_QUAD = 4;

    Vector2u levelSize;
    // a2Level[x][y]
    Tile **a2Level;
    VertexArray bgVA;
    void makeBGVertexArray();
    // Deletes the level array
    void deleteLevel();
};