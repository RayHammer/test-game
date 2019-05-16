#pragma once
#include "Headers.h"
#include "Singleton.h"
#include "IEntity.h"

class EntityManager : public Singleton<EntityManager> {
public:
    EntityManager();
    ~EntityManager();

    void createEntity(IEntity *const &e);
    void updateAll(const Time &dt);
    void drawAll(RenderTarget &target, const RenderStates &states = RenderStates::Default);
private:
    void cleanup();
    vector<IEntity *> entities;
    queue<IEntity *> entityCleanup;
    Thread thrCleanup;
    Mutex mtxCleanup;
    bool isRunning;
};