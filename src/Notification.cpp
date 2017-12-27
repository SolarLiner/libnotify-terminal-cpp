#include "Notification.hpp"

Notification::Notification(std::string appname, std::string title, std::string body)
{
    notify_init(appname.c_str());
    n = notify_notification_new(title.c_str(), body.c_str(), 0);
    notify_notification_set_app_name(n, appname.c_str());
}

Notification::~Notification() { }

void Notification::set_timeout(int ms)
{
    notify_notification_set_timeout(n, ms);
}

void Notification::set_icon(std::string icon)
{
    notify_notification_set_category(n, icon.c_str());
}

bool Notification::show()
{
    return notify_notification_show(n, 0);
}
