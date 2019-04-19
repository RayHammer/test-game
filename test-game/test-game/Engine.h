#pragma once
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "LevelManager.h"
#include "TextureManager.h"

using namespace sf;

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
    LevelManager levManager;
    TextureManager texManager;
    Level* level;
};