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
    d.swap_card_positions(0,51);
    CHECK(d.cards[0].to_string() == "Ace of Spades");
    CHECK(d.cards[51].to_string() == "2 of Clubs");
}

TEST_CASE("Test remove_card and add_card") {
    Deck deck;
    deck.shuffle();
    CHECK(deck.cards.size() == 52);
    Card c = deck.remove_card();
    CHECK(deck.cards.size() == 51);
    Deck deck2(0);
    CHECK(deck2.cards.size() == 0);
    deck2.add_card(c);
    CHECK(deck2.cards.size() == 1);
    CHECK((deck2.cards[0] == c) == true);
}

TEST_CASE("Test can swap two random cards") {
    Card c1(HEARTS, QUEEN);
    Card c2(DIAMONDS, JACK);
    swap_cards(c1, c2);
    CHECK(c1.to_string() == "Jack of Diamonds");
    CHECK(c2.to_string() == "Queen of Hearts");
}

TEST_CASE("Test create subdecks") {
    Deck deck;
    Deck subdeck = deck.subdeck(2, 10);
    CHECK(subdeck.cards.size() == 9);
    CHECK(subdeck.cards[0].to_string() == "4 of Clubs");
}

TEST_CASE("Test add_cards and merge_sort") {
    Deck d1(0);
    Deck d2(0);
    d1.add_card(Card(HEARTS, QUEEN));
    d1.add_card(Card(SPADES, ACE));
    d1.add_card(Card(CLUBS, FOUR));
    d1.add_card(Card(DIAMONDS, FOUR));
    d2.add_card(Card(CLUBS, FIVE));
    d2.add_card(Card(HEARTS, TEN));
    d2.add_card(Card(CLUBS, TWO));
    d1.add_cards(d2);
    Deck d3 = d1.merge_sort();
    CHECK(d3.cards[0].to_string() == "Two of Clubs");
}