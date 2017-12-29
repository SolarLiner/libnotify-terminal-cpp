CXX=clang++
LIBS=libnotify
FLAGS=-std=c++11 -O3
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(patsubst src/%.cpp,%.bc,$(SOURCES))

.PHONY: make debug tests clean

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

clean:
	-rm *.bc *.gc[nd][oa]
	-rm -rf build
	-rm tests.out
