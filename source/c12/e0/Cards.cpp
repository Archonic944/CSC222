#include <string>
#include <vector>
#include <iostream>
#include "Cards.h"
using namespace std;


vector<string> suit_strings = {"None", "Clubs", "Diamonds",
                                   "Hearts", "Spades"};
vector<string> rank_strings = {"Joker", "Ace", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "Jack", "Queen",
                                   "King"};
string Card::to_string() const {
    if (rank == 0) return rank_strings[rank];
    else return rank_strings[rank] + " of " + suit_strings[suit];
}

Card::Card(){
    suit = 0;
    rank = 0;
}

Card::Card(int s, int r){
    suit = s;
    rank = r;
}

bool Card::operator>(const Card& card) const {
    return false;
}

bool Card::operator==(const Card& card) const {
    return false;
}