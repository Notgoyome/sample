#include "core/renderer/objects/VAO.hpp"
using namespace core::renderer;

VAO::VAO(VBO &vbo, EBO &_ebo) {
	glGenVertexArrays(1, &id);
	glBindVertexArray(id);
	vbo.bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	vbo.unbind();
}

VAO::~VAO() {
}

void VAO::bind() const {
}

void VAO::unbind() const {
}