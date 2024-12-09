#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include <string>
#include "Cards.h"
using namespace std;

TEST_CASE("Test can create Cards") {
    Card c1;
    CHECK(c1.suit == 0);
    CHECK(c1.rank == 0);
    Card c2(3, 4);
    CHECK(c2.suit == 3);
    CHECK(c2.rank == 4);
}

TEST_CASE("Test can render Cards") { //NOTE: This test has been changed from the provided one. Please see my commit description ("Implement Ace Value") for more information.
    Card c3(3, 11);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(2, 9);
    CHECK(c4.to_string() == "10 of Diamonds");
    Card c5;
    CHECK(c5.to_string() == "Joker");
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