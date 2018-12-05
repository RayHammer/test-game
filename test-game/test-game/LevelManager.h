#pragma once

#include "Level.h"
#include <string>

class LevelManager
{
public:
    LevelManager();
    ~LevelManager();
    bool load(Level * level, const std::string & path);
private:
    Level * level;
};

