#pragma once
#include "Entity.h"
#include "TextureManager.h"

using namespace sf;

typedef Keyboard::Key Key;

class Player : public Entity
{
public:
    Player();
    ~Player();
    void update(Time dt);
    virtual void draw(RenderTarget& target, RenderStates states) const;
private:
    Key key_left = Key::A;
    Key key_right = Key::D;
};

