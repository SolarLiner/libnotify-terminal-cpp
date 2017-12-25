#include <iostream>
#include "../lib/args/args.hxx"


void help()
{
    std::cout << "libnotify-terminal is a small program that interfaces ";
    std::cout << "with libnotify, allowing you to send notifications from ";
    std::cout << "commandline. Contrary to notify-send, this supports ";
    std::cout << "callbacks, allowing you to place buttons." << std::endl;
}

int main(int argc, char **argv)
{
    args::ArgumentParser parser("Short text #1", "This goes after the options");
    args::HelpFlag help(parser, "help", "Displays this help menu", {'h', "help"});

    try
    {
        
    }
    catch (args::Help h)
    {
        std::cout << parser;
        return 0;
    }
    catch(args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    return 0;
}
