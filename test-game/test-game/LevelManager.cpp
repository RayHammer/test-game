#include "LevelManager.h"



LevelManager::LevelManager() {
    level = NULL;
}

LevelManager::~LevelManager() {
    
}

bool LevelManager::load(Level * level, const std::string & path) {
    if (level != NULL)
        delete this->level;
    this->level = level;
    return level->loadFromFile(path);
}