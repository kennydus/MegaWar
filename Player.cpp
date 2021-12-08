//
// Created by kenny on 12/6/2021.
//

#include "Player.h"

double Player::getFierceness() {
    int rankSum = 0;
    vector<Card>::iterator iter;

    if (pile.empty())   // meaning the player has no cards
        return 0;

    for (iter = pile.begin(); iter < pile.end(); iter++)
        rankSum += iter->getValue();
    double fiercenessRounded = (double) rankSum / pile.size();
    fiercenessRounded = (int)(fiercenessRounded * 100.0)/100.0;
    return fiercenessRounded;
}

int Player::getNumBattles() {
    return numBattles;
}

int Player::getNumWins() {
    return numWins;
}

void Player::addBattle() {
    numBattles++;
}

void Player::addWin() {
    numWins++;
}
