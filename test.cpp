#include "View.h"
#include "Player.h"
#include "doctest.h"


TEST_CASE("setViewCamera") {
    CHECK(setViewCamera({30, 10}).getCenter() == sf::Vector2f(204, 152));
    CHECK(setViewCamera({780, -10}).getCenter() == sf::Vector2f(756, 152));
    CHECK(setViewCamera({200, 500}).getCenter() == sf::Vector2f(204, 152));
    CHECK(setViewCamera({1000, 750}).getCenter() == sf::Vector2f(756, 152));
}

TEST_CASE("getPosition") {
    {Player player({ 32, 44 }, { 200, 120 }, "files/hero.png");
    CHECK(player.getPosition() == sf::Vector2f(200, 120));}
    {Player player({ 32, 44 }, { 100, 500 }, "files/hero.png");
    CHECK(player.getPosition() == sf::Vector2f(100, 500));}
    {Player player({ 32, 44 }, { -10, -50 }, "files/hero.png");
    CHECK(player.getPosition() == sf::Vector2f(-10, -50));}
}
