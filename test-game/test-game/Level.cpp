#include "Level.h"

using namespace std;

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
    while (getline(inputFile, s)) {
        levelSize.y++;
    }
    levelSize.x = s.length();
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    // Writing data to the array
    a2Level = new Tile *[levelSize.x];
    for (Uint32 i = 0; i < levelSize.x; i++) {
        a2Level[i] = new Tile[levelSize.y];
    }
    printf_s("Loading a level...\n");
    for (Uint32 j = 0; j < levelSize.y; j++) {
        getline(inputFile, s);
        for (Uint32 i = 0; i < levelSize.x; i++) {
            a2Level[i][j] = s.at(i) - '0';
            printf_s("%d ", a2Level[i][j]);
        }
        printf_s("\n");
    }
    return true;
}

void Level::deleteLevel() {
    if (a2Level == nullptr) return;
    for (unsigned int i = 0; i < levelSize.x; i++) {
        delete[] a2Level[i];
    }
    delete[] a2Level;
    a2Level = nullptr;
}