#pragma once
#define ENGINE_H

#include "Singleton.h"
#include "Player.h"
#include "LevelManager.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include <vector>

using namespace sf;
using namespace std;

class Engine : public Singleton<Engine> {
public:
    static void start() {
        getInstance().run();
    }
private:
    Engine();
    ~Engine();

    void run();

    void init();

    void loadContent();

    void handleEvent(const Event & event);

    void update();

    void draw();

    RenderWindow window;
    LevelManager& levManager = LevelManager::getInstance();
    TextureManager& texManager = TextureManager::getInstance();
    // EntityManager& entManager = EntityManager::getInstance();
    vector<Entity*> entities;

    unsigned int framerate = 60;
};