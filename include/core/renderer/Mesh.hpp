#pragma once

#include "objects/EBO.hpp"
#include "objects/VAO.hpp"
#include "objects/VBO.hpp"
#include <glad.h>
#include <memory>
namespace core::renderer {
class Mesh {
public:
	Mesh(GLfloat vertices[], GLuint indices[], int vertexCount, int indexCount);
	~Mesh();

private:
	std::unique_ptr<core::renderer::VAO> vao;
	std::unique_ptr<core::renderer::VBO> vbo;
	std::unique_ptr<core::renderer::EBO> ebo;
};
} //namespace core::renderer
