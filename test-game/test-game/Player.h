#pragma once
#include "Entity.h"
#include "TextureManager.h"

using namespace sf;

class Player : public Entity
{
public:
    Player();
    ~Player();
    void update(Time dt);
    virtual void draw(RenderTarget& target, RenderStates states) const;
};

