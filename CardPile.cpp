//
// Created by kenny on 12/6/2021.
//

#include "CardPile.h"


void CardPile::addCard(Card card) {
    pile.push_back(card);
}

Card CardPile::removeCard() {
    Card topCard = pile[0];
    pile.erase(pile.begin());
    return topCard;
}

int CardPile::getNumCards() {
    return pile.size();
}
