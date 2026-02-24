#pragma once

#include "../IGLObject.hpp"
#include "EBO.hpp"
#include "VBO.hpp"
#include <glad.h>
namespace core::renderer {
class VAO : public IGLObject {
public:
	VAO(VBO &vbo, EBO &_ebo);
	~VAO();

	void bind() const override;
	void unbind() const override;

private:
	GLuint id;
};
} //namespace core::renderer