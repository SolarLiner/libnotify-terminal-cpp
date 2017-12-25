#include <libnotify/notify.h>
#include <string>
#include <cstdio>
#include <iostream>

class IO {
public:
    template<class T> bool read(T &out);
    bool write(string format, ...);
}