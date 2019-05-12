#pragma once
#include "Singleton.h"
#include "Entity.h"
#include <vector>
#include <queue>

using namespace std;
using namespace sf;

class EntityManager : public Singleton<EntityManager> {
public:
    EntityManager();
    ~EntityManager();
    bool add(Entity *const &entity);
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