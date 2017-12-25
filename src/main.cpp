#include <iostream>
#include "IO.hpp"

void help()
{
    std::cout << "libnotify-terminal is a small program that interfaces ";
    std::cout << "with libnotify, allowing you to send notifications from ";
    std::cout << "commandline. Contrary to notify-send, this supports ";
    std::cout << "callbacks, allowing you to place buttons." << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
