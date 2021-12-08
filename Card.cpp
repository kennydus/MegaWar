//
// Created by kenny on 12/6/2021.
//

#include "Card.h"
#include <iostream>

//Card::Card() {
//    rank = 'X';
//    suit = 'X';
//}

Card::Card(RANK r, SUIT s) {
    rank = r;
    suit = s;
}

void Card::setCard(RANK r, SUIT s) {
    rank = r;
    suit = s;

}
int Card::getValue() {      // Returning the respective values of the "ace" and "face" cards
    switch (rank){
        case ACE: return 1;
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN: return 10;
        case JACK: return 11;
        case QUEEN: return 12;
        case KING: return 13;
    }
}


void Card::showCard() {

    switch (rank){
        case ACE: cout << "A"; break;
        case TWO: cout << "2"; break;
        case THREE: cout << "3"; break;
        case FOUR: cout << "4"; break;
        case FIVE: cout << "5"; break;
        case SIX: cout << "6"; break;
        case SEVEN: cout << "7"; break;
        case EIGHT: cout << "8"; break;
        case NINE: cout << "9"; break;
        case TEN: cout << "10"; break;
        case JACK: cout << "J"; break;
        case QUEEN: cout << "Q"; break;
        case KING: cout << "K"; break;
        default: cout << "Rank Unknown";
    }
    switch (suit){
        case(HEART): cout << "H"; break;
        case(DIAMOND): cout << "D"; break;
        case(CLUB): cout << "C"; break;
        case(SPADE): cout << "S"; break;
    }
}

bool Card::operator<(Card right){
    return rank < right.rank;

}
