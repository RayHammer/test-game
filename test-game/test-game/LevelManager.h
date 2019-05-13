#pragma once
#include "Headers.h"
#include "ResourceManager.h"
#include "Level.h"

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