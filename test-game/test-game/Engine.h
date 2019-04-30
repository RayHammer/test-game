#pragma once
#define ENGINE_H

#include "Player.h"
#include "LevelManager.h"
#include "TextureManager.h"
#include <vector>

using namespace sf;
using namespace std;

class Engine {
public:
    Engine(const Engine & engine) = delete;
    Engine operator=(Engine & engine) = delete;

    static Engine & getInstance() {
        static Engine instance;
        return instance;
    }

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
    vector<Entity*> entities;
};