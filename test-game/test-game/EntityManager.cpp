#include "EntityManager.h"

EntityManager::EntityManager() : thrCleanup(&EntityManager::cleanup, this) {
    isRunning = true;
}

EntityManager::~EntityManager() {
    isRunning = false;
    thrCleanup.wait();
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if (*it != nullptr) {
            delete* it;
        }
    }
}

void EntityManager::createEntity(IEntity *const &e) {
    entities.push_back(e);
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
            mtxCleanup.lock();
            entityCleanup.push(*it);
            mtxCleanup.unlock();
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

void EntityManager::cleanup() {
    while (isRunning) {
        if (!entityCleanup.empty()) {
            mtxCleanup.lock();
            IEntity *p = entityCleanup.front();
            entityCleanup.pop();
            mtxCleanup.unlock();
            delete p;
        }
    }
}