#include "doctest/catch.hpp"
#include "View.h"

TEST_CASE("setViewCamera") {
    CHECK(setViewCamera(30, 20) == (204, 152));
    CHECK(setViewCamera(780, 20) == (756, 152));
}
