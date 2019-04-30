#pragma once
#include <SFML/Graphics.hpp>
#include <cstdio>

using namespace sf;

class Entity : public Drawable
{
public:
    Entity() {}
    virtual ~Entity() {}
    virtual void update(Time dt) = 0;
    virtual void draw(RenderTarget& target, RenderStates states) const = 0;
protected:
    Sprite sprite;
};