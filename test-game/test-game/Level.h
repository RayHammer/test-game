#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

using namespace sf;

typedef int Tile;

class Level
{
public:
    Level();
    ~Level();
    bool loadFromFile(const std::string & path);
private:
    Vector2u levelSize;
    // a2Level[x][y]
    Tile **a2Level;
    // Deletes the level array
    void deleteLevel();
};

