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
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	~Mesh();

	VAO &getVAO() const { return *vao; }
	int getVertexCount() const { return vertexCount; }
	int getIndicesCount() const { return indicesCount; }
	void draw() const;

private:
	int vertexCount;
	int indicesCount;

	std::shared_ptr<core::renderer::VAO> vao;
	std::shared_ptr<core::renderer::VBO> vbo;
	std::shared_ptr<core::renderer::EBO> ebo;
};
} //namespace core::renderer