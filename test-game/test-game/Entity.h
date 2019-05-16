#pragma once
#include "Headers.h"
#include "IEntity.h"
#include "EntityManager.h"
#include "TextureManager.h"

class Entity : public IEntity {
public:
    Entity() {}
    virtual ~Entity() {}
    virtual void update(Time dt) = 0;
    virtual void draw(RenderTarget& target, RenderStates states) const {}
    bool isDestroyed() {
        return destroyed;
    }
protected:
    void createEntity(IEntity *const &e) {
        EntityManager::getInstance().createEntity(e);
    }
    Texture &getTexture(const string &path) {
        return TextureManager::getInstance().getTexture(path);
    }
    bool destroyed = false;
    Vector2f pos;
    Sprite sprite;
};