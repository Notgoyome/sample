#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    Window();
    ~Window();

    void process();
    bool shouldClose() const;
private:
    GLFWwindow* window;
};