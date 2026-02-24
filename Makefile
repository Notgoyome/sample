.PHONY: rebuild clean run build

rebuild:
	rm -rf build
	cmake -S . -B build
	cmake --build build

build:
	cmake --build build

run: build
	./build/app

clean:
	rm -rf build