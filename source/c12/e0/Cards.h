#include <string>

using namespace std;

enum Suit { NONE, CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank { JOKER, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
            NINE, TEN, JACK, QUEEN, KING, ACE };

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