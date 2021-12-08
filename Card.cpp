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
    if (rank == 'A')
        return 1;
    else if (rank == 'T')
        return 10;
    else if (rank == 'J')
        return 11;
    else if (rank == 'Q')
        return 12;
    else if (rank == 'K')
        return 13;

    return (int) rank - 48;     // Converting ASCII values of the "number" cards back to their actual integer values
}


void Card::showCard() {

//    if (rank == 'T'){
//        cout << "10" << suit;
//    }
//    else
//        cout << rank << suit;
//
//    cout << " ";
    switch (rank){
        case ACE: cout << "1"; break;
        case TWO: cout << "2"; break;
        case THREE: cout << "3"; break;
        case FOUR: cout << "4"; break;
        case FIVE: cout << "5"; break;
        case SIX: cout << "6"; break;
        case SEVEN: cout << "7"; break;
        case EIGHT: cout << "8"; break;
        case NINE: cout << "9"; break;
        case TEN: cout << "10"; break;
        case JACK: cout << "11"; break;
        case QUEEN: cout << "12"; break;
        case KING: cout << "13"; break;
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
