CXX=clang++
FLAGS=`pkg-config --cflags --libs libnotify`

make: libnotify-terminal

libnotify-terminal: src/*.cpp
	mkdir -p build
	clang++ $^ $(FLAGS) -o build/$@

clean:
	rm -rf build
