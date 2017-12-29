#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../src/Notification.hpp"

TEST_CASE("a Notification object is being created", "[Notification]") {
	REQUIRE_NOTHROW([&]() {
		Notification n("Application", "Title", "Body");
		n.set_timeout(5e3);
		n.show();
	});
}

TEST_CASE("Notifiction shows successfully", "[Notification]") {
	Notification n("Application", "Title", "Body");
	REQUIRE(n.show() == true);
}
