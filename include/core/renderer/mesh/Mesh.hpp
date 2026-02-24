#pragma once

#include "Vertex.hpp"
#include "objects/EBO.hpp"
#include "objects/VAO.hpp"
#include "objects/VBO.hpp"
#include <glad.h>
#include <memory>

namespace core::renderer {
class Mesh {
public:
	Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> indices);
	~Mesh();

	VAO &getVAO() const { return *vao; }

private:
	std::unique_ptr<core::renderer::VAO> vao;
	std::unique_ptr<core::renderer::VBO> vbo;
	std::unique_ptr<core::renderer::EBO> ebo;
};
} //namespace core::renderer