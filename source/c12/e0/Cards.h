#include <string>

using namespace std;

enum Suit { NONE, CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank { JOKER, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
            NINE, TEN, JACK, QUEEN, KING, ACE };

//Single card structure
struct Card
{
    Suit suit;
    Rank rank;
    Card();
    Card(int s, int r);
    bool operator==(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;
    bool operator!=(const Card&) const;
    string to_string() const;
};

void swap_cards(Card& c1, Card& c2);

// Deck structure
struct Deck {
    vector<Card> cards;

    Deck(int size);
    Deck();
    void print() const;
    void shuffle();
    void sort();
    Deck subdeck(int l, int h) const;
    void add_card(const Card& c);
    Card remove_card();
    void swap_card_positions(int i, int j);
    int find(const Card& c) const;
};