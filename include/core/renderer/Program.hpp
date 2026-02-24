#pragma once
#include "utils/Parse.hpp"
#include <glad.h>

namespace core::renderer {

class Program {
public:
	Program(std::string vertexPath, std::string fragmentPath);
	~Program();

	void use() const;
	void bufferData(int buffer, int size, const void *data, int usage) const;

	GLuint getProgramID() const { return id; }

private:
	GLuint id;
};

} //namespace core::renderer