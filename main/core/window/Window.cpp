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
	GLuint textureId = renderer->setTexture("assets/text.png");

	std::vector<Vertex> vertices = {
		{ { -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f } }, // LD
		{ { 0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } }, // RD
		{ { -0.5f, 0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } }, // LT
		{ { 0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } }, // RT
	};

	std::vector<GLuint> indices = {
		0,
		1,
		2,

		2,
		1,
		3,

	};

	mesh = std::make_unique<core::renderer::Mesh>(vertices, indices, textureId);
	// EndTemporary
	renderer->addMesh(*mesh);
}

Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::process() {
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	renderer->render();
	glfwSwapBuffers(window);

	glfwPollEvents();
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(window);
}