#include "core/renderer/Renderer.hpp"

using namespace core::renderer;

Renderer::Renderer() :
		program("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl") {
}

Renderer::~Renderer() {
}

void Renderer::render() const {
	program.use();
	for (const auto &mesh : meshes) {
		mesh.getVAO().bind();
		glDrawElements(GL_TRIANGLES, mesh.getIndicesCount(), GL_UNSIGNED_INT, 0);
	}
}