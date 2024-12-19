#include <string>
#include <vector>
#include <iostream>
#include "Cards.h"
using namespace std;


vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
vector<string> rank_strings = {"Joker", "None", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "Jack", "Queen",
                                   "King", "Ace"}; //i didn't want to change the enum values... but they leave a gap between joker and 2. I inserted "none." pretty bad but whatever

string Card::to_string() const {
    if (rank == 0) return rank_strings[rank];
    else return rank_strings[rank] + " of " + suit_strings[suit];
}

Card::Card(){
    suit = Suit::NONE;
    rank = Rank::JOKER;
}

Card::Card(int s, int r){
    suit = Suit(s);
    rank = Rank(r);
}

bool Card::operator>(const Card& c) const {
    if(c.suit > suit) return false;
    else if(c.suit < suit) return true;
    else return rank > c.rank;
}

bool Card::operator<(const Card& c) const{
    return !(*this > c) && !(*this == c); //could be made more efficient by not dereferencing twice
}

bool Card::operator<=(const Card& c) const{
    return !(*this > c);
}

bool Card::operator>=(const Card& c) const{
    return (*this > c) || (*this == c);
}

bool Card::operator==(const Card& c2) const {
    return (rank == c2.rank && suit == c2.suit);
}

bool Card::operator!=(const Card& c2) const {
    return !(this->operator==(c2));
}

// Implement left shift operator
ostream& operator<<(ostream& os, const Card& c){
    os << c.to_string();
    return os;
}