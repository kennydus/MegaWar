//
// Created by kenny on 12/6/2021.
//

#ifndef MEGAWAR_CARD_H
#define MEGAWAR_CARD_H
#include <string>
using namespace std;

enum SUIT {HEART, DIAMOND, CLUB, SPADE};
enum RANK {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
private:
    RANK rank;
    SUIT suit;
public:
//    Card();
    Card(RANK r, SUIT s);
    void setCard(RANK r, SUIT s);
    int getValue();
    void showCard();
//    char getSuit(); //added for MegaWar
    bool operator<(Card);
};


#endif //MEGAWAR_CARD_H
