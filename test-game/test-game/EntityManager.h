#pragma once
#include "Singleton.h"
#include "Entity.h"

class EntityManager : public Singleton<EntityManager> {
public:
    
private:
    EntityManager();
    ~EntityManager();
};

