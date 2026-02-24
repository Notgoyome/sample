#include "utils/Parse.hpp"

std::string readFile(const std::string &path) {
	std::ifstream file(path);
	std::stringstream buffer;

	buffer << file.rdbuf();

	return buffer.str();
}
