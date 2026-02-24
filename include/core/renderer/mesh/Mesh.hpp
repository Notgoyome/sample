#pragma once

#include "../Program.hpp"
#include "Vertex.hpp"
#include "objects/EBO.hpp"
#include "objects/VAO.hpp"
#include "objects/VBO.hpp"
#include <glad.h>
#include <memory>

namespace core::renderer {
class Mesh {
public:
	// Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, GLuint textureID);

	~Mesh();

	VAO &getVAO() const { return *vao; }
	int getVertexCount() const { return vertexCount; }
	int getIndicesCount() const { return indicesCount; }
	void draw(const core::renderer::Program *program) const;
	void bindTexture(const core::renderer::Program *program) const;

private:
	int vertexCount;
	int indicesCount;
	GLuint textureID;

	std::shared_ptr<core::renderer::VAO> vao;
	std::shared_ptr<core::renderer::VBO> vbo;
	std::shared_ptr<core::renderer::EBO> ebo;
};
} //namespace core::renderer