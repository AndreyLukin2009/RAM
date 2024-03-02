#include "RandomAccessMemory.h"

RandomAccessMemory::RandomAccessMemory(size_t width, size_t height,
    size_t offsetX, size_t offsetY) : 
    WindowInfo(width, height, offsetX, offsetY),
    currentX(0), currentY(0)
{
    s.dwLength = sizeof(s);
}

DWORD RandomAccessMemory::getMemLoad() {
    GlobalMemoryStatusEx(&s);

    return s.dwMemoryLoad;
}


void RandomAccessMemory::update() {
    if (currentX >= width)
        currentX = 0;

   currentY = getMemLoad();

   sf::Vertex v;
   v.position.x = currentX + offsetX;
   v.position.y = 100 - currentY + offsetY;

   data[currentX] = v;

}

const std::vector<sf::Vertex>& RandomAccessMemory::getData() const {
    return data;
}

const size_t RandomAccessMemory::getSize() const {
    return data.size();
}

void RandomAccessMemory::clear() {
    data.clear();
}