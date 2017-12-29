CXX=clang++
LIBS=libnotify
FLAGS=-std=c++11 -O3
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(patsubst src/%.cpp,%.bc,$(SOURCES))

.PHONY: make debug tests package clean

make: libnotify-terminal

debug: FLAGS+=-g
debug: libnotify-terminal

%.bc: src/%.cpp
	$(CXX) -emit-llvm -o $@ -c $^ $(FLAGS) `pkg-config --cflags $(LIBS)`

libnotify-terminal: $(OBJS)
	mkdir -p build
	$(CXX) $^ -o build/$@ `pkg-config --libs $(LIBS)`

tests: $(filter-out src/main.cpp,$(SOURCES) $(wildcard tests/*.cpp))
	@echo "Building tests executable"
	@$(CXX) $(FLAGS) -fprofile-arcs -ftest-coverage --coverage -g `pkg-config --cflags --libs $(LIBS)` -o $@.out $^
	@echo "Cleaning old coverage tests"
	-@rm -rf ./tests/coverage
	@echo "Runing tests"
	-@./$@.out

package: build
	-mkdir -p dist/libnotify-terminal
	cp build/libnotify-terminal dist/libnotify-terminal
	tar -zcvf libnotify-terminal.tar.gz -C dist libnotify-terminal

clean:
	-rm *.bc *.gc[nd][oa] *.tar.gz
	-rm -rf build dist
	-rm tests.out
