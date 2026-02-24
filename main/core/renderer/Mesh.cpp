#include "core/renderer/Mesh.hpp"
using namespace core::renderer;

Mesh::Mesh(GLfloat vertices[], GLuint indices[], int vertexCount, int indexCount) {
	vbo = std::make_unique<core::renderer::VBO>(vertices, vertexCount);
	ebo = std::make_unique<core::renderer::EBO>(indices, indexCount);
	vao = std::make_unique<core::renderer::VAO>(*vbo, *ebo);

	ebo->bind();
}

Mesh::~Mesh() {
}