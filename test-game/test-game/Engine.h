#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Engine {
public:
    Engine(const Engine & engine) = delete;
    Engine operator=(Engine & engine) = delete;

    static Engine & getInstance() {
        static Engine instance;
        return instance;
    }

    static void start() {
        getInstance().run();
    }
private:
    Engine();
    ~Engine();

    void run();

    void init();

    void loadContent();

    void handleEvent(const Event & event);

    void update();

    void draw();

    RenderWindow window;
};

#endif // ENGINE_H