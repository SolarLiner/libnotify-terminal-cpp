CXX=clang++
FLAGS=`pkg-config --cflags --libs libnotify`

make: libnotify-terminal

libnotify-terminal: *.cc
	-mkdir build
	clang++ $^ $(FLAGS) -o build/$@

clean:
	rm -rf build
