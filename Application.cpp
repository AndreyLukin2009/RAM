#include "Application.h"

Application* Application::s_Instance = nullptr;

Application::Application(size_t width, size_t height, std::string windowName) {
    window = new sf::RenderWindow(sf::VideoMode(width, height), windowName);

    ram = new RandomAccessMemory(200, 100, 50, 50);
}

void Application::run() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        ram->update();

        window->clear();
        window->draw(
            &ram->getData()[0],
            ram->getSize(),
            sf::LinesStrip
        );
        window->display();

    }
}

Application& Application::getInstance(size_t width, size_t height, std::string windowName) {
    if (s_Instance == nullptr)
        s_Instance = new Application(width, height, windowName);
    return *s_Instance;
}

Application& Application::getInstance() {
    return *s_Instance;
}


Application::~Application() {
    if (window != nullptr)
        delete window;
}