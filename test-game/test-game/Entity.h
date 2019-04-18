#pragma once
#include "Level.h"
#include <SFML/System.hpp>

class Entity
{
public:
    Entity();
    virtual ~Entity();
    void update(sf::Time dt) {}
    void draw() {}
protected:
    Level *pLevel;
};

