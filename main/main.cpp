
#include "core/window/Window.hpp"

int main() {
	Window window;

	while (!window.shouldClose()) {
		window.process();
	}

	return 0;
}
