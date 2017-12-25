#ifndef IO_H
#define IO_H
#include <string>
#include <iostream>
#include "../lib/args/args.hxx"

class IO
{
public:
    template<class T> static bool read(const std::string info, T& output);
    template<class T> static bool write(T& input);
};

#endif