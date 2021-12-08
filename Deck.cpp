//
// Created by kenny on 12/6/2021.
//

#include <algorithm>
#include <random>
#include <iostream>
#include "Deck.h"
#include <vector>

//Card deck[52];
vector<Card> deck;
int cardsInADeck = 52;
std::random_device rd;

Deck::Deck() {      // constructor which creates a deck of 52 cards
    numCardsLeft = 52;
    for (int s = HEART; s <= SPADE; ++s){
        for (int r = ACE; r <= KING; ++r){
            deck.push_back(Card(static_cast<RANK>(r), static_cast<SUIT>(s)));
        }
    }

}

void Deck::addDeck() {
    numCardsLeft = 52;
    Deck();
}

Card Deck::deal() {
    Card topCard = deck[0];
    deck.erase(deck.begin());
    numCardsLeft--;
    return topCard;
}

void Deck::shuffle() {

    std::shuffle(deck.begin(), deck.end(), rd);
//    for (int i = 0; i < cardsInADeck; i = i + 2) {   // swapping every other card with another random card
//        int randIndex = rand() % 52;                 // rather than all for simplicity.
//        Card temp = deck[i];                        // making temporary card in order to swap
//        deck[i] = deck[randIndex];
//        deck[randIndex] = temp;
//    }
}

int Deck::cardsLeft() {
    return numCardsLeft;
}

void Deck::showDeck() {
    int counter = 0;
    for (auto i = deck.begin(); i != deck.end(); ++i) {
        i->showCard();
        cout << " ";
        if (++counter % 13 == 0)
            cout << endl;
    }
}