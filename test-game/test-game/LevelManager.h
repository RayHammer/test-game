#pragma once

#include "ResourceManager.h"
#include "Level.h"

using namespace std;

class LevelManager : public ResourceManager<Level>
{
public:
    LevelManager();
    ~LevelManager();
    bool load(const string & path);
    Level* getLevel();
private:
    Level level;
};

