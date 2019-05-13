#pragma once
#include "Headers.h"

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
    bool destroyed = false;
    Vector2f pos;
    Sprite sprite;
};