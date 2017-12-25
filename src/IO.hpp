#ifndef IO_H
#define IO_H
#include <string>
#include <iostream>

class IO
{
public:
    IO();
    ~IO();
    template<class T> bool read(const std::string info, T& output);
    template<class T> bool write(T& input);
    bool parse_args(int argc, std::string* argv);
};

#endif