#pragma once
#include "Program.hpp"
#include "mesh/Mesh.hpp"
#include <glad.h>
namespace core::renderer {

class Renderer {
public:
	Renderer();
	~Renderer();

	void addMesh(const Mesh &mesh) { meshes.push_back(mesh); }
	void removeMesh(size_t index) { meshes.erase(meshes.begin() + index); }
	void clearMeshes() { meshes.clear(); }

	void render() const;

private:
	core::renderer::Program program;
	std::vector<core::renderer::Mesh> meshes;
};

} //namespace core::renderer