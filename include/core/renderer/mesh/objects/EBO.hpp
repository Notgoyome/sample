#pragma once

#include "../../IGLObject.hpp"
#include <glad.h>
#include <vector>
namespace core::renderer {
class EBO : public IGLObject {
public:
	EBO(std::vector<GLuint> indices);
	~EBO();

	void bind() const override;
	void unbind() const override;

private:
	GLuint id;
};
} //namespace core::renderer