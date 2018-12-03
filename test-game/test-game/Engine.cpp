#include "Engine.h"

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::run() {
    init();
    loadContent();
    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            handleEvent(e);
        }
        update();
        window.clear();
        draw();
        window.display();
    }
    return;
}

void Engine::init() {
    window.create(VideoMode(1280, 720), "Game Window", Style::Titlebar | Style::Close);
    return;
}

void Engine::loadContent() {
    return;
}

void Engine::handleEvent(const Event & e) {
    if (e.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
    return;
}

void Engine::update() {
    return;
}

void Engine::draw() {
    return;
}