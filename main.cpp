#include <iostream>
#include "Deck.h"
#include "MegaDeck.h"
#include "CardPile.h"
#include "Player.h"
#include "LostAndFound.h"
#include "WarPile.h"



int main() {
    int numPlayers;
    int numDecks;
    cout<<"How many players will be playing MegaWar?" << endl;
    cin >> numPlayers;
    while(numPlayers <= 1){
        cout<<"How many players will be playing MegaWar?" << endl;
        cin >> numPlayers;
    }
    cout<<"How many decks will be used?:" << endl;
    cin >> numDecks;
    while(numDecks < 1) {
        cout<<"How many decks will be used?:" << endl;
        cin >> numDecks;
    }
    vector<Player> players(numPlayers);
    MegaDeck megaDeck(numDecks);
    megaDeck.shuffle();
    megaDeck.showDeck();


    return 0;

}

//    MegaDeck deck;
//    deck.showDeck();
//    deck.shuffle();
//    cout << "\n";
//    deck.showDeck();
//    Card c1 = deck.deal();
//    cout << "\ndeal: ";
//    c1.showCard();
//    cout << endl;
//    deck.showDeck();
//    Card c2 = deck.deal();
//    cout << "\n\ndeal: ";
//    c1.showCard();
//    cout << " ";
//    c2.showCard();
//    cout << endl;
//    deck.showDeck();
//    deck.addDeck();
//    cout << "\n\nAdded a new deck:"<<endl;
//    deck.showDeck();
//    deck.shuffle();
//    cout << "\n\nShuffled Megadeck:"<<endl;
//    deck.showDeck();
//
//    cout << "\n\nIs c1 < c2 ?: " << (c1 < c2);