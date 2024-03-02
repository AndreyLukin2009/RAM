#pragma once
#include "WindowInfo.h"

class RandomAccessMemory : public WindowInfo
{
public:

    RandomAccessMemory(size_t, size_t, size_t, size_t);

    DWORD getMemLoad();

    void update() final;
    void clear() final;

    const std::vector<sf::Vertex>& getData() const;
    const size_t getSize() const;

private:
    MEMORYSTATUSEX s;

    size_t currentX;
    size_t currentY;

};

