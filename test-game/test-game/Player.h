#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
public:
    Player(Level *pLevel);
    ~Player();
    void update(sf::Time dt);
    void draw();
private:

};

