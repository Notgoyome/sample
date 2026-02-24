
#include <iostream>
#include <GLFW/glfw3.h>

int initWindow() {
    if (!glfwInit()) {
        std::cerr << "GLFW init failed";
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "opengl project", nullptr, nullptr);
    if (!window) {
        std::cerr << "Window failed";
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

int main() {
    std::cout << "hello world" << std::endl;

    if (initWindow() == -1) return -1;

    return 1;
}
