#include "Window.hpp"

Window::Window() {
    if (!glfwInit()) {
        throw std::runtime_error("GLFW init failed");
    }

    window = glfwCreateWindow(800, 600, "opengl project", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Window failed");
    }
    glfwMakeContextCurrent(window);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::process() {
        glfwPollEvents();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}