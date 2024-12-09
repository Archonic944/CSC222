#include <string>

using namespace std;
struct Card
{
    int suit, rank;
    //a handy-dandy enumeration for if you want to initialize a card of a specific suit
    static const int NONE = 0;
    static const int CLUBS = 1;
    static const int HEARTS = 2;
    static const int SPADES = 3;
    static const int DIAMONDS = 4;
    static const vector<Card> build_deck();
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