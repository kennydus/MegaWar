//
// Created by kenny on 12/7/2021.
//

#ifndef MEGAWAR_PLAYER_H
#define MEGAWAR_PLAYER_H


#include "CardPile.h"

class Player : public CardPile {
private:
    int numBattles = 0;
    int numWins = 0;
public:
    double getFierceness();

};


#endif //MEGAWAR_PLAYER_H
