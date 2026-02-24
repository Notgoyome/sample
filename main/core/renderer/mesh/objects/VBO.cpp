#include "core/renderer/mesh/objects/VBO.hpp"
using namespace core::renderer;

VBO::VBO(const size_t size, const void *datas) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, datas, GL_STATIC_DRAW);
}

VBO::~VBO() {
	glDeleteBuffers(1, &id);
}

void VBO::bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}