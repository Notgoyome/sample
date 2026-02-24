#include "core/renderer/mesh/Mesh.hpp"
using namespace core::renderer;

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
	const size_t vertexSize = vertices.size() * sizeof(Vertex);

	vbo = std::make_unique<core::renderer::VBO>(vertexSize, vertices.data());
	ebo = std::make_unique<core::renderer::EBO>(indices);
	vao = std::make_unique<core::renderer::VAO>();

	vao->bind();

	vao->linkVBO(*vbo, 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)0);
	vao->linkVBO(*vbo, 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
	ebo->bind();
}

Mesh::~Mesh() {
}