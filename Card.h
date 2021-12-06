//
// Created by kenny on 12/6/2021.
//

#ifndef MEGAWAR_CARD_H
#define MEGAWAR_CARD_H
#include <string>
using namespace std;


class Card {
private:
    char rank;
    char suit;
public:
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void showCard();
    char getSuit(); //added for MegaWar
};


#endif //MEGAWAR_CARD_H
