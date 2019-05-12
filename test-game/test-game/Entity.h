#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include <cstdio>

using namespace sf;

class Entity : public Drawable
{
public:
    Entity() {}
    virtual ~Entity() {}
    virtual void update(Time dt) = 0;
    virtual void draw(RenderTarget& target, RenderStates states) const {}
    bool isDestroyed() {
        return destroyed;
    }
protected:
    void entityCreate(Entity *const &entity) {
        EntityManager::getInstance().add(entity);
    }
    bool destroyed = false;
    Vector2f pos;
    Sprite sprite;
};