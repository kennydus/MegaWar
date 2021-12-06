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

Deck::Deck() {      // constructor which creates a deck of 52 cards. ace of spades is on top, followed by the other
    numCardsLeft = 52;  // spades in order, then followed by hearts --> diamonds --> clubs (same order)
    char rankDict[13] = {'A' , '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suitDict[4] = {'S', 'D', 'H', 'C'};
//    int index = 0;
    for (int suit = 0; suit < 4; suit++){
        for (int rank = 0; rank < 13; rank++) {
            deck.push_back(Card(rankDict[rank], suitDict[suit]));
//            deck[index].setCard(rankDict[rank], suitDict[suit]);
//            index++;
        }
    }

}

void Deck::refreshDeck() {  // resets the number of cards left, and recreates the deck to look like a new one.
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