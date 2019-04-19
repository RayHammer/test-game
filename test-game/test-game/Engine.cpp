#include "Engine.h"

Engine::Engine() {
    this->level = NULL;
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
        draw();
    }
    return;
}

void Engine::init() {
    window.create(VideoMode(1280, 720), "Game Window", Style::Titlebar | Style::Close);
    return;
}

void Engine::loadContent() {
    levManager.load("Assets/Levels/level0.txt");
    texManager.load("Assets/Textures/tileset.png");
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
    window.clear();
    auto& texture = texManager.getTexture("Assets/Textures/tileset.png");
    auto& bgVA = levManager.getLevel()->getVertexArray();
    window.draw(bgVA, &texture);
    window.display();
    return;
}