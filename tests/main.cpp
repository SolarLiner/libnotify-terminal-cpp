#define CATCH_CONFIG_MAIN
#include "../lib/test/catch.hpp"
#include "../src/Notification.hpp"

TEST_CASE("a Notification object is being created", "[Notification]") {
	Notification n("Application", "Title", "Body");
	REQUIRE(n != null);
}
