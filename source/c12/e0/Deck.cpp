#include <string>
#include <iostream>
#include "Cards.h"
#include <vector>

//utils
int random_between(int low, int high) {
    return low + rand() % (high - low + 1);
}

void Deck::print() const {
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].to_string() << endl;
    }
}

int Deck::find(const Card& c) const{
    for(int i = 0; i<cards.size(); i++){
        if(cards[i] == c) return i;
    }
    return -1;
}

//constructors
Deck::Deck(int size) {
    vector<Card> temp(size);
    cards = temp;
}

Deck::Deck() {
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit + 1)) {
        for (Rank rank = TWO; rank <= ACE; rank = Rank(rank + 1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

//mutators
void Deck::shuffle() {
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}

void Deck::sort() {
    for (int i = 0; i < cards.size() - 1; i++) {
        //find the lowest card at or to the right of i
        //swwap the ith card and the lowest card
        int lowest_index = i;
        for(int j = i; j<cards.size(); j++){
            if(cards[j] < cards[lowest_index]) lowest_index = j;
        }
        swap_cards(i, lowest_index);
    }
}

//add/change contents
Deck Deck::subdeck(int l, int h) const {
    Deck sub(h - l + 1);
    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards[i] = cards[l + i];
    }
    return sub;
}

void Deck::add_card(const Card& c) {
    cards.push_back(c);
}

Card Deck::remove_card() {
    Card card = cards[cards.size() - 1];
    cards.pop_back();
    return card;
}

void Deck::swap_cards(int i, int j) {
    if(i == j) return;
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}