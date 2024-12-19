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

TEST_CASE("Test for comparison of Cards") {
    Card c1(HEARTS, QUEEN);
    Card c2(HEARTS, QUEEN);
    Card c3(SPADES, ACE);
    Card c4(HEARTS, FIVE);
    Card c5(HEARTS, FOUR);
    Card c6(DIAMONDS, FOUR);
    CHECK((c1 == c2) == true);
    CHECK((c1 == c3) == false);
    CHECK((c1 != c3) == true);
    CHECK((c1 > c5) == true);
    CHECK((c1 <= c5) == false);
    CHECK((c6 < c5) == true);
    CHECK((c5 >= c6) == true);
}

TEST_CASE("Test comparisons with Aces") { //NOTE: This test has been changed from the provided one. Please see my commit description ("Implement Ace Value") for more information.
    Card ace(4, 13);
    Card c2(4, 2);
    Card c3(4, 1);
    CHECK(ace > c2);
    CHECK(ace > c3);
}

TEST_CASE("Test create Deck with two constructors") {
    Deck d1(10);
    CHECK(d1.cards.size() == 10);
    CHECK(d1.cards[0].to_string() == "Joker");
    Deck d2;
    CHECK(d2.cards.size() == 52);
    CHECK(d2.cards[0].to_string() == "2 of Clubs");
    CHECK(d2.cards[51].to_string() == "Ace of Spades");
}

TEST_CASE("Test find Card in Deck") {
    Deck d;
    Card c(HEARTS, QUEEN);
    int pos = d.find(c);
    CHECK(d.cards[pos].to_string() == "Queen of Hearts");
    // Create non-existant card to confirm it isn't in the deck
    Card c2(NONE, QUEEN);
    int pos2 = d.find(c2);
    CHECK(pos2 == -1);
}

TEST_CASE("Test can sort Cards in deck"){
    Deck d = Deck();
    d.shuffle();
    d.sort();
    CHECK(d.cards[0].to_string() == "2 of Clubs");
    CHECK(d.cards[51].to_string() == "Ace of Spades");
}

TEST_CASE("Test can shuffle Cards in deck"){
    Deck d = Deck();
    d.shuffle();
    CHECK(d.cards[0].to_string() != "2 of Clubs");
    //there is a 1/52 chance that this test case will fail, even if the deck truly "shuffles"...
}

TEST_CASE("Test can swap Cards in deck"){
    Deck d = Deck();
    d.swap_cards(0,51);
    CHECK(d.cards[0].to_string() == "Ace of Spades");
    CHECK(d.cards[1].to_string() == "2 of Clubs");
}