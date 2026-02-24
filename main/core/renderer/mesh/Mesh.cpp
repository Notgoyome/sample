#include "core/renderer/mesh/Mesh.hpp"
using namespace core::renderer;

Mesh::Mesh(GLfloat vertices[], GLuint indices[], int vertexCount, int indexCount) {
	vbo = std::make_unique<core::renderer::VBO>(vertices, vertexCount);
	ebo = std::make_unique<core::renderer::EBO>(indices, indexCount);
	vao = std::make_unique<core::renderer::VAO>();

	vao->bind();
	vao->linkVBO(*vbo, 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)0);
	vao->linkVBO(*vbo, 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
	ebo->bind();
}

Mesh::~Mesh() {
}