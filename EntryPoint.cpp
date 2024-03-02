#include "Application.h"

int main() {
    Application& app = Application::getInstance(800, 600, "MainWindow");

    app.run();

     return 0;
}