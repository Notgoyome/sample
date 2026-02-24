#include "core/renderer/mesh/objects/EBO.hpp"
using namespace core::renderer;

EBO::EBO(GLuint indices[], int count) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, GL_STATIC_DRAW);
}

EBO::~EBO() {
	glDeleteBuffers(1, &id);
}

void EBO::bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}