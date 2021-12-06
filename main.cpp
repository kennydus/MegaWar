#include <iostream>
#include "Deck.h"

int main() {
    Deck deck;
    deck.showDeck();
    deck.shuffle();
    cout << "\n";
    deck.showDeck();
    Card c1 = deck.deal();
    cout << "\ndeal: ";
    c1.showCard();
    cout << endl;
    deck.showDeck();
    Card c2 = deck.deal();
    cout << "\ndeal: ";
    c1.showCard();
    cout << " ";
    c2.showCard();
    cout << endl;
    deck.showDeck();



    return 0;

}
