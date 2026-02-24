#include "core/renderer/mesh/objects/VAO.hpp"
using namespace core::renderer;

VAO::VAO() {
	glGenVertexArrays(1, &id);
}

VAO::~VAO() {
}

void VAO::linkVBO(VBO &vbo, GLuint layout, int size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
	vbo.bind();
	glVertexAttribPointer(layout, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(layout);
	vbo.unbind();
}

void VAO::bind() const {
	glBindVertexArray(id);
}

void VAO::unbind() const {
	glBindVertexArray(0);
}