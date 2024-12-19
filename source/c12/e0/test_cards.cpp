#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
#include "Cards.h"
using namespace std;

TEST_CASE("Test can create and render Cards") {
    Card c1(DIAMONDS, JACK);
    CHECK(c1.to_string() == "Jack of Diamonds");
    Card c2;
    CHECK(c2.to_string() == "Joker");
    Card c3(HEARTS, QUEEN);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(SPADES, SEVEN);
    CHECK(c4.to_string() == "7 of Spades");
}

TEST_CASE("Can compare Cards"){
    Card c1(1, 1);
    Card c2(1,1);
    Card c3(1,2);
    Card c4(2,2);
    Card c5(1,3);

    CHECK(c1 == c2);
    CHECK(c3 > c2);
}

TEST_CASE("Test comparison of Cards") {
    Card c1(2, 9);
    Card c2(1, 9);
    Card c3(1, 10);
    Card c4(1, 10);
    CHECK(c2 < c1);
    CHECK(!(c3 <= c2));
    CHECK(c1 >= c3);
    CHECK(c3 == c4);
    CHECK(!(c3 != c4));
}

TEST_CASE("Test comparisons with Aces") { //NOTE: This test has been changed from the provided one. Please see my commit description ("Implement Ace Value") for more information.
    Card ace(4, 13);
    Card c2(4, 2);
    Card c3(4, 1);
    CHECK(ace > c2);
    CHECK(ace > c3);
}

