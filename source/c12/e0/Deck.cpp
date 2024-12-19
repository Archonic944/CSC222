#include <iostream>
#include <string>
#include "Cards.h"
#include <vector>

struct Deck {
    vector<Card> cards;

    Deck(int size) {
        vector<Card> temp(size);
        cards = temp;
    }

    Deck() {
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

    void print() const {
        for (int i = 0; i < cards.size(); i++) {
            cout << cards[i].to_string() << endl;
        }
    }

    void shuffle() {
        for (int i = 0; i < cards.size(); i++) {
            int rand_card = random_between(0, cards.size() - 1);
            swap_cards(i, rand_card);
        }
    }

    void sort() {
        for (int i = 0; i < cards.size(); i++) {
            //find the lowest card at or to the right of i
            //swwap the ith card and the lowest card
        }
    }

    Deck subdeck(int l, int h) const {
        Deck sub(h - l + 1);
        for (int i = 0; i < sub.cards.size(); i++) {
            sub.cards[i] = cards[l + i];
        }
        return sub;
    }

    void add_card(const Card& c) {
        cards.push_back(c);
    }

    Card remove_card() {
        Card card = cards[cards.size() - 1];
        cards.pop_back();
        return card;
    }

    int random_between(int low, int high) {
        return 0;
    }

    void swap_cards(int i, int j) {
        
    }
};