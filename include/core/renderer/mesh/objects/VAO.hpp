#pragma once

#include "../../IGLObject.hpp"
#include "EBO.hpp"
#include "VBO.hpp"
#include <glad.h>
namespace core::renderer {
class VAO : public IGLObject {
public:
	VAO();
	~VAO();
	/* layout position, number of value in the variable, the type of the value, normalized, stride, pointer */
	// layout: the location of the variable in the shader
	// size: the number of values in the variable (ex 3 for vec3)
	// type: the type of the value (ex GL_FLOAT)
	// normalized: whether the value should be normalized (ex GL_FALSE)
	// stride: the byte offset between consecutive vertex attributes (ex 6 * sizeof(GLfloat) for a vertex with 3 position values and 3 color values)
	// pointer: the offset of the first component of the first vertex attribute in the buffer (e.g. (void *)0 for the first attribute)
	void linkVBO(VBO &vbo, GLuint layout = 0, int size = 3, GLenum type = GL_FLOAT, GLboolean normalized = GL_FALSE, GLsizei stride = 0, const void *pointer = nullptr);
	void bind() const override;
	void unbind() const override;

private:
	GLuint id;
};
} //namespace core::renderer