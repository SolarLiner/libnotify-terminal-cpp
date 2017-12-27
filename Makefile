CXX=clang++
LIBS=libnotify
FLAGS=-std=c++11 -O3
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(patsubst src/%.cpp,%.bc,$(SOURCES))

make: libnotify-terminal

debug: FLAGS+=-g
debug: libnotify-terminal

%.bc: src/%.cpp
	clang++ -emit-llvm -o $@ -c $^ $(FLAGS) `pkg-config --cflags $(LIBS)`

libnotify-terminal: $(OBJS)
	mkdir -p build
	clang++ $^ -o build/$@ `pkg-config --libs $(LIBS)`

clean:
	-rm *.bc
	-rm -rf build
