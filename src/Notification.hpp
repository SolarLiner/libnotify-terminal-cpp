#include <libnotify/notify.h>
#include <string>

class Notification
{
public:
    Notification(std::string appname, std::string title, std::string body);
    ~Notification();
    void set_timeout(int ms);
    void set_icon(std::string icon);

    bool show();

private:
    NotifyNotification* n;
};
