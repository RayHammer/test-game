#include "LevelManager.h"

LevelManager::LevelManager() {
    
}

LevelManager::~LevelManager() {
    
}

bool LevelManager::load(const std::string & path) {
    return level.loadFromFile(path);
}

Level* LevelManager::getLevel() {
    return &this->level;
}