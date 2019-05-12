#pragma once
#include "Singleton.h"
#include "Entity.h"
#include <vector>

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
    vector<Entity*> entities;
};