#include "core/window/Window.hpp"
#include "utils/Parse.hpp"

Window::Window() {
	int width = 800;
	int height = 600;

	if (!glfwInit()) {
		throw std::runtime_error("GLFW init failed");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, "opengl project", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		throw std::runtime_error("Window failed");
	}
	glfwMakeContextCurrent(window);
	int result = gladLoadGL();
	if (!result) {
		throw std::runtime_error("Failed to initialized GLAD");
	}

	renderer = std::make_shared<core::renderer::Renderer>();

	glViewport(0, 0, width, height);

	// Temporary
	std::vector<Vertex> vertices = {
		{ { -0.9f, -0.5f, 0.0f }, { 1.0f, 1.0f, 1.0f } }, // DL
		{ { 0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f } }, // DR
		{ { 0.0f, 0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f } }, // Top
		// { { 0.5f, 0.5f, 0.0f }, { 0.0f, 0.1f, 1.0f } } // TR
	};

	std::vector<GLuint> indices = {
		0,
		1,
		2, // First triangle
		// 1, 2, 3 // Second triangle
	};

	mesh = std::make_unique<core::renderer::Mesh>(vertices, indices);
	// EndTemporary
	renderer->addMesh(*mesh);
}

Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::process() {
	glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	renderer->render();
	glfwSwapBuffers(window);

	glfwPollEvents();
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(window);
}