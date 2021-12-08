//
// Created by kenny on 12/6/2021.
//

#include "MegaDeck.h"


MegaDeck::MegaDeck() = default;

MegaDeck::MegaDeck(int numDecks) {
    // MegaDeck begins with 1 deck (from Deck constructor), so add 1 less than the specified numDecks
    for (int i = 0; i < numDecks - 1; i++)
        addDeck();
}


