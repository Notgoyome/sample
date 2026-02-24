#include "core/renderer/Renderer.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace core::renderer;

Renderer::Renderer() :
		program("main/assets/shaders/vertex.glsl", "main/assets/shaders/fragment.glsl") {
}

Renderer::~Renderer() {
}

void Renderer::render() const {
	program.use();
	for (const core::renderer::Mesh &mesh : meshes) {
		mesh.draw(&program);
	}
}

GLuint Renderer::setTexture(std::string texturePath) {
	int width, height, nChannels;
	unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nChannels, 0);
	if (!data) {
		throw std::runtime_error("Failed to load texture: " + texturePath);
	}
	GLuint textureCurrentID;

	glGenTextures(1, &textureCurrentID);
	GLuint id = textureCurrentID;

	glBindTexture(GL_TEXTURE_2D, textureCurrentID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLenum format = nChannels == 4 ? GL_RGBA : GL_RGB;
	if (format == GL_RGB) {
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
	return id;
}