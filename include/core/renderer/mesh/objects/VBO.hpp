#pragma once

#include "../../IGLObject.hpp"
#include <glad.h>
#include <cstddef>

namespace core::renderer {
class VBO : public IGLObject {
public:
	VBO(const size_t size, const void *vertices);
	~VBO();

	void bind() const override;
	void unbind() const override;

private:
	GLuint id;
};
} //namespace core::renderer