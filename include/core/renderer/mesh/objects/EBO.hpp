#pragma once

#include "../../IGLObject.hpp"
#include <glad.h>
namespace core::renderer {
class EBO : public IGLObject {
public:
	EBO(GLuint indices[], int count);
	~EBO();

	void bind() const override;
	void unbind() const override;

private:
	GLuint id;
};
} //namespace core::renderer