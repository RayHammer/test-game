#pragma once

#include "ResourceManager.h"
#include "Level.h"

using namespace std;

class LevelManager : public ResourceManager<LevelManager, Level>
{
public:
    LevelManager();
    ~LevelManager();
    bool load(const string & path);
    Level* getLevel();
private:
    Level level;
};

