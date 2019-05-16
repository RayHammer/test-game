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
    window.setFramerateLimit(framerate);
    return;
}

void Engine::loadContent() {
    levManager.load("Assets/Levels/level0.txt");
    texManager.load("Assets/Textures/tileset.png");
    texManager.load("Assets/Textures/default.png");
    entManager.createEntity(new Player());
    return;
}

void Engine::handleEvent(const Event & e) {
    if (e.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
    return;
}

void Engine::update() {
    Time dt = sf::seconds(1.f / framerate);
    entManager.updateAll(dt);
    return;
}

void Engine::draw() {
    auto &texture = texManager.getTexture("Assets/Textures/tileset.png");
    auto &bgVA = levManager.getLevel()->getVertexArray();
    window.draw(bgVA, &texture);
    entManager.drawAll(window);
    return;
}