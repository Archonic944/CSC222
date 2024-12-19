#include <string>
#include <iostream>
#include "Cards.h"
#include <vector>

//utils
int random_between(int low, int high) {
    return low + rand() % (high - low + 1);
}

void Deck::print() const {
    cout << "Deck, size = " << cards.size() << endl;
    for (int i = 0; i < cards.size(); i++) {
        cout << " " << cards[i].to_string() << endl;
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
        swap_card_positions(i, rand_card);
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
        swap_card_positions(i, lowest_index);
    }
}

//**add/change contents**

//creates a subdeck of [l,h]
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

void Deck::swap_card_positions(int i, int j) {
    if(i == j) return;
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

void Deck::add_cards(const Deck& deck){
    for(int i = 0; i<deck.cards.size(); i++){
        cards.push_back(deck.cards[i]);
    }
}

Deck merge(Deck& left, Deck& right){ //merges two sorted decks into one sorted deck
    int i = 0;
    int j = 0;
    Deck d(0);
    while(i < left.cards.size() && j < right.cards.size()){
        if(left.cards[i] < right.cards[j]){
            d.add_card(left.cards[i]);
            i++;
        }else{
            d.add_card(right.cards[j]);
            j++;
        }
    }
    //merge leftovers from left
    while(i < left.cards.size()){
        d.add_card(left.cards[i]);
        i++;
    }

    //merge leftovers from right
    while(j < right.cards.size()){
        d.add_card(right.cards[i]);
        j++;
    }
    return d;
}

Deck Deck::merge_sort(){
    int size = cards.size();
    if(size <= 1) return (*this);
    int mid = (size) / 2;
    Deck left = subdeck(0, mid - 1).merge_sort();
    Deck right = subdeck(mid, size - 1).merge_sort();
    return merge(left, right);
}