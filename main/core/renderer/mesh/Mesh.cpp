#include "core/renderer/mesh/Mesh.hpp"
using namespace core::renderer;

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, GLuint textureID) : textureID(textureID) {
	const size_t vertexSize = vertices.size() * sizeof(Vertex);

	vertexCount = vertices.size();
	indicesCount = indices.size();

	vbo = std::make_unique<core::renderer::VBO>(vertexSize, vertices.data());
	ebo = std::make_unique<core::renderer::EBO>(indices);
	vao = std::make_unique<core::renderer::VAO>();

	vao->bind();
	ebo->bind();

	vao->linkVBO(*vbo, 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
	vao->linkVBO(*vbo, 1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));
	vao->linkVBO(*vbo, 2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, texCoords)));
}

void Mesh::bindTexture(const core::renderer::Program *program) const {
	glUseProgram(program->getProgramID());
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	GLuint location = glGetUniformLocation(program->getProgramID(), "u_texture");
	glUniform1i(location, 0);
}

Mesh::~Mesh() {
}

void Mesh::draw(const core::renderer::Program *program) const {
	vao->bind();
	bindTexture(program);
	glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, 0);
}