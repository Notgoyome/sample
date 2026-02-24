#include "core/renderer/Program.hpp"
using namespace core::renderer;

Program::Program(std::string vertexPath, std::string fragmentPath) {
	// TODO: shader class

	// Vertex
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexShaderSource = readFile(vertexPath);
	//"assets/shaders/vertex.glsl"
	const char *vertexShaderSourceCStr = vertexShaderSource.c_str();
	glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, NULL);
	glCompileShader(vertexShader);

	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cerr << "vertex shader compilation failed:\n"
				  << infoLog << std::endl;
	}

	// Fragments
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragmentShaderSource = readFile(fragmentPath);
	//"assets/shaders/fragment.glsl"
	const char *fragmentShaderSourceCStr = fragmentShaderSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, NULL);
	glCompileShader(fragmentShader);

	GLint success2;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success2);
	if (!success2) {
		char infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cerr << "fragment shader compilation failed:\n"
				  << infoLog << std::endl;
	}

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);

	glLinkProgram(id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Program::~Program() {
	glDeleteProgram(id);
}

void Program::use() const {
	glUseProgram(id);
}