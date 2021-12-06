//
// Created by kenny on 12/6/2021.
//

#include "Card.h"
#include <iostream>

Card::Card() {
    rank = 'X';
    suit = 'X';
}

Card::Card(char r, char s) {
    rank = r;
    suit = s;
}

void Card::setCard(char r, char s) {
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

    if (rank == 'T'){
        cout << "10" << suit;
    }
    else
        cout << rank << suit;

    cout << " ";
}
