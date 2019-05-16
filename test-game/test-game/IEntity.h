#pragma once
#include "Headers.h"

class IEntity : public Drawable {
public:
    IEntity() {}
    virtual ~IEntity() {}
    virtual void update(Time dt) = 0;
    virtual void draw(RenderTarget &target, RenderStates states) const = 0;
    virtual bool isDestroyed() = 0;
};