#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <string>

#include "RandomAccessMemory.h"

//enum class ApplicationState : uint8_t
//{
//    NONE = 0,
//    RUNNING,
//    PAUSE,
//    FINISH
//};

class Application {
public:
    Application(const Application&) = delete;
    void operator=(const Application&) = delete;

    void run();

    static Application& getInstance(size_t, size_t, std::string);
    static Application& getInstance();

    ~Application();

private:
    Application(size_t, size_t, std::string);
    static Application* s_Instance;

    sf::RenderWindow* window;

    RandomAccessMemory* ram;
};

