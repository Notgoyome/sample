#pragma once
#include <glad.h>

namespace core::renderer {

class Renderer {
public:
	Renderer(int width, int height);
	~Renderer();

private:
	int width;
	int height;
};

} //namespace core::renderer