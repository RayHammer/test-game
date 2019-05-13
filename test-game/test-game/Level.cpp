#include "Level.h"
#include "Utility.h"

using namespace util;

Level::Level() {
    a2Level = nullptr;
}

Level::~Level() {
    deleteLevel();
}

bool Level::loadFromFile(const std::string & path) {
    deleteLevel();
    levelSize = Vector2u(0, 0);
    fstream inputFile(path.c_str());
    string s;
    // Getting level dimensions
    inputFile >> levelSize.x >> levelSize.y;
    getline(inputFile, s);
    // Writing data to the array
    a2Level = new Tile *[levelSize.x];
    for (Uint32 i = 0; i < levelSize.x; i++) {
        a2Level[i] = new Tile[levelSize.y];
    }
    for (Uint32 j = 0; j < levelSize.y; j++) {
        getline(inputFile, s);
        vector<int> parsed_res;
        //if (!parse_CSV(s.begin(), s.end(), parsed_res) || parsed_res.size() < levelSize.x) {
        if (!parse_CSV_int(s, parsed_res) || parsed_res.size() < levelSize.x) {
            return false;
        }
        for (Uint32 i = 0; i < levelSize.x; i++) {
            a2Level[i][j] = parsed_res[i];
        }
    }
    makeBGVertexArray();
    return true;
}

void Level::makeBGVertexArray() {
    bgVA.setPrimitiveType(Quads);
    bgVA.resize(levelSize.x * levelSize.y * VERTS_IN_QUAD);
    for (int i = 0; i < levelSize.x; i++) {
        for (int j = 0; j < levelSize.y; j++) {
            int currVertex = (i * levelSize.y + j) * 4;
            int tileType = a2Level[i][j];

            bgVA[currVertex + 0].position =
                Vector2f(i * TILE_SIZE, j * TILE_SIZE);
            bgVA[currVertex + 1].position =
                Vector2f((i + 1) * TILE_SIZE, j * TILE_SIZE);
            bgVA[currVertex + 2].position =
                Vector2f((i + 1) * TILE_SIZE, (j + 1) * TILE_SIZE);
            bgVA[currVertex + 3].position =
                Vector2f(i * TILE_SIZE, (j + 1) * TILE_SIZE);

            bgVA[currVertex + 0].texCoords =
                Vector2f(0, 0 + TILE_SIZE * tileType);
            bgVA[currVertex + 1].texCoords =
                Vector2f(TILE_SIZE, 0 + TILE_SIZE * tileType);
            bgVA[currVertex + 2].texCoords =
                Vector2f(TILE_SIZE, TILE_SIZE + TILE_SIZE * tileType);
            bgVA[currVertex + 3].texCoords =
                Vector2f(0, TILE_SIZE + TILE_SIZE * tileType);
        }
    }
}

void Level::deleteLevel() {
    if (a2Level == nullptr) return;
    for (unsigned int i = 0; i < levelSize.x; i++) {
        delete[] a2Level[i];
    }
    delete[] a2Level;
    a2Level = nullptr;
}