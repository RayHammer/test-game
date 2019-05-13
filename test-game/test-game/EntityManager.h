#pragma once
#include "Headers.h"
#include "Singleton.h"
#include "Entity.h"

class EntityManager : public Singleton<EntityManager> {
public:
    EntityManager();
    ~EntityManager();
    void add(Entity *const &entity);
    void updateAll(const Time &dt);
    void drawAll(RenderTarget &target, const RenderStates &states = RenderStates::Default);
private:
    void cleanup();
    vector<Entity*> entities;
    queue<Entity*> entityCleanup;
    Thread thrCleanup;
    Mutex mtxCleanup;
    bool isRunning;
};