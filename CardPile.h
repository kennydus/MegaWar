//
// Created by kenny on 12/6/2021.
//

#ifndef MEGAWAR_CARDPILE_H
#define MEGAWAR_CARDPILE_H

#include "Card.h"
#include <vector>


class CardPile {
protected:
    vector<Card> pile;
public:
    void addCard();
    Card removeCard();
    //sort?


};


#endif //MEGAWAR_CARDPILE_H
