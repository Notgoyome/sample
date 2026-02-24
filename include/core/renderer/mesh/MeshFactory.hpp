#pragma once
#include "IGLObject.hpp"
#include "Mesh.hpp"
#include <glad.h>

namespace core::renderer {
class MeshFactory {
public:
	static Mesh createPlane();
	static Mesh createTriangle();
};
} //namespace core::renderer