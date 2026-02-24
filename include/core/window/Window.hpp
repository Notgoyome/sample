#pragma once

#define GLFW_INCLUDE_NONE
#include "core/renderer/Program.hpp"
#include "core/renderer/mesh/Mesh.hpp"

#include <GLFW/glfw3.h>
#include <glad.h>
#include <iostream>
#include <memory>
#include <stdexcept>
class Window {
public:
	Window();
	~Window();

	void process();
	bool shouldClose() const;

private:
	GLFWwindow *window;
	// core::renderer::Mesh *mesh;
	std::unique_ptr<core::renderer::Mesh> mesh;
	std::unique_ptr<core::renderer::Program> program;
};