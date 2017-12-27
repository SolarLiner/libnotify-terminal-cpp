#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "../lib/args/args.hxx"
#include "Notification.hpp"

int main(int argc, const char** argv)
{
    args::ArgumentParser parser("Display notifications from command-line, with callbacks.");
    args::HelpFlag help(parser, "help", "Displays this help menu", {'h', "help"});

    args::Group content(parser, "Add content to your notification", args::Group::Validators::DontCare);
    args::Positional<std::string> body(content, "body", "Notification body", args::Options::Required);
    args::ValueFlag<std::string> title(content, "title", "Notification title", {'t', "title"});
    args::ValueFlag<std::string> icon(content, "icon", "freedesktop icon name", {"icon"}, args::Options::Single);

    args::Group config(parser, "Configuration options", args::Group::Validators::DontCare);
    args::ValueFlag<std::string> appname(config, "appname", "Application name", {"appname"}, args::Options::Required);
    args::ValueFlag<int> timeout(config, "timeout", "Notification timeout. Only applies to DEs that support it.", {"timeout"});

    args::Group buttons(parser, "Add buttons to the notification (if the desktop environment supports it)", args::Group::Validators::DontCare);
    args::ValueFlag<std::string> button(buttons, "button", "Adds a button by its action callback and user label", {"button"});

    parser.LongSeparator(" ");

    try
    {
        std::vector<std::string> args(argv+1, argv+argc);
        parser.Prog(argv[0]);
        parser.ParseArgs(args);

        //parser.ParseCLI(argc, argv);
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
    catch(args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    Notification n(args::get(appname), args::get(title), args::get(body));
    n.set_timeout(5000);

    if(n.show()) return 0;

    std::cerr << "Could not display notification." << std::endl;
    return -1;
}
