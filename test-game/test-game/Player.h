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
private:
    int movSpeed = 240;

    Keyboard::Key key_up = Keyboard::W;
    Keyboard::Key key_left = Keyboard::A;
    Keyboard::Key key_down = Keyboard::S;
    Keyboard::Key key_right = Keyboard::D;
};

