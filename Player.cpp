//
// Created by kenny on 12/7/2021.
//

#include "Player.h"

double Player::getFierceness() {
    int rankSum = 0;
    vector<Card>::iterator iter;
    for (iter = pile.begin(); iter < pile.end(); iter++)
        rankSum += iter->getValue();
    double fierceness = double(rankSum) / getNumCards();
    return fierceness;
}
