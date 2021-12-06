//
// Created by kenny on 12/6/2021.
//

#ifndef MEGAWAR_DECK_H
#define MEGAWAR_DECK_H

#include "Card.h"

class Deck {
public:
    Deck();
    int numCardsLeft;
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};


#endif //MEGAWAR_DECK_H
