#include "EntityManager.h"


EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if (*it != nullptr) {
            delete* it;
        }
    }
}

bool EntityManager::add(Entity *const &entity) {
    entities.push_back(entity);
    return true;
}

void EntityManager::updateAll(const Time &dt) {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if (*it == nullptr) {
            break;
        }
        auto &i = (**it);
        if (!i.isDestroyed()) {
            i.update(dt);
        } else {
            delete* it;
            *it = nullptr;
        }
    }
}

void EntityManager::drawAll(RenderTarget &target, const RenderStates &states) {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if (*it == nullptr) {
            break;
        }
        auto &i = (**it);
        if (!i.isDestroyed()) {
            target.draw(i);
        }
    }
}