#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#include "Headers.h"
#include "Singleton.h"
#include "Player.h"
#include "LevelManager.h"
#include "TextureManager.h"
#include "EntityManager.h"

class Engine : public Singleton<Engine> {
public:
    Engine();
    ~Engine();
    static void start() {
        getInstance().run();
    }
private:
    void run();

    void init();

    void loadContent();

    void handleEvent(const Event &event);

    void update();

    void draw();

    RenderWindow window;
    LevelManager &levManager = LevelManager::getInstance();
    TextureManager &texManager = TextureManager::getInstance();
    EntityManager &entManager = EntityManager::getInstance();
    vector<Entity *> entities;

    unsigned int framerate = 60;
};
#endif // ENGINE_H