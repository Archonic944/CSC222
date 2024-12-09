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
    return "";
}

Card::Card(){

}

Card::Card(int s, int r){
    
}