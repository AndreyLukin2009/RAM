#pragma once

#include <vector>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <Windows.h>

class WindowInfo
{
public:
    WindowInfo(size_t width, size_t height, size_t offsetX, size_t offsetY) :
        width(width), height(height),
        offsetX(offsetX), offsetY(offsetY) {

        data.resize(width);

        for (size_t idx = 0; idx < width; idx++) {
            data[idx] = sf::Vertex(sf::Vector2f(idx + offsetX, 0 + offsetY));
        }

    }

    virtual const std::vector<sf::Vertex>& getData() const = 0;
    virtual const size_t getSize() const = 0;
    virtual void update() const = 0;
    virtual void clear() const = 0;

    virtual ~WindowInfo() = default;

protected:

    std::vector<sf::Vertex> data;

        size_t width;
        size_t height;


        size_t offsetX;
        size_t offsetY;
        
};
