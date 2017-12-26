CXX=clang++
LIBS=libnotify
FLAGS=-std=c++11

make: libnotify-terminal

debug: src/*.cpp
	mkdir -p build/debug
	clang++ $^ $(FLAGS) -g `pkg-config --cflags --libs $(LIBS)` -o build/debug/libnotify-terminal

libnotify-terminal: src/*.cpp
	mkdir -p build
	clang++ $^ $(FLAGS) `pkg-config --cflags --libs $(LIBS)` -o build/$@

clean:
	rm -rf build
