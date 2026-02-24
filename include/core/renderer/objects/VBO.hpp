#pragma once

#include "../IGLObject.hpp"
#include <glad.h>
namespace core::renderer {
class VBO : public IGLObject {
public:
	VBO(GLfloat vertices[], int count);
	~VBO();

	void bind() const override;
	void unbind() const override;

private:
	GLuint id;
};
} //namespace core::renderer