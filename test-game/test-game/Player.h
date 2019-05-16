#pragma once
#include "Headers.h"
#include "Entity.h"
#include "TextureManager.h"

class Player : public Entity {
public:
    Player();
    ~Player();
    virtual void update(Time dt);
    virtual void draw(RenderTarget& target, RenderStates states) const;
private:
    int movSpeed = 240;

    Keyboard::Key key_up = Keyboard::W;
    Keyboard::Key key_left = Keyboard::A;
    Keyboard::Key key_down = Keyboard::S;
    Keyboard::Key key_right = Keyboard::D;
};