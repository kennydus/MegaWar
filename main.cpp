//  Kenny Du
//  Class (CECS 282-01)
//  Project Name (Prog 6 – MegaWar / Inheritance)
//  Due Date (12/08/21)
//
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Deck.h"
#include "MegaDeck.h"
#include "CardPile.h"
#include "Player.h"
#include "LostAndFound.h"
#include "WarPile.h"



int main() {
    WarPile warFaceUps;
    WarPile warPile;
    LostAndFound lostAndFound;

    int battleNum = 1;
    int numPlayers;
    int numDecks;
    int numPlayersDead = 0;

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

    //Deal cards to players
    //push_back
    int playerNum = 0;  //keeps track of which player we are dealing to
    while (megaDeck.cardsLeft() > 0){
        players[playerNum].addCard(megaDeck.deal());
        playerNum++;
        playerNum = playerNum % numPlayers;     // ensures that we are only giving cards to those in 'players' vector
    }

    while (numPlayersDead < (numPlayers - 1)){
        //Find out whose card is the greatest
        int rankMax = 0;
        Player* battleWinner = nullptr;
        vector<Player*> pAtWar;

        // Normal Battle
        for (int i = 0; i < numPlayers; i++){
//            rankMax = 0;

            if (players[i].getNumCards() > 0){      // only live players
                Card temp = players[i].removeCard();
                warPile.addCard(temp);
                players[i].addBattle();
                if (temp.getValue() > rankMax) {    // check if current player's card is the highest
                    rankMax = temp.getValue();
                    battleWinner = &players[i];
                    pAtWar.clear();     // since this card is the new max, clear the candidates for war
                    pAtWar.push_back(&players[i]);
                }
                // if the card is the same rank of another in the pile, make them a candidate for war
                else if (temp.getValue() == rankMax){
                    pAtWar.push_back(&players[i]);
                }
            }
        }
//        cout << "\nCards in normal battle: ";
//        for (int i = 0; i < warPile.getNumCards(); i++){
//            warPile.showCard(i);
//            cout << " ";
//        }
//        cout << endl;


        // go to war!
        if (pAtWar.size() > 1) {
//            cout << "\nWe are in a war: " << endl;
            vector<Player*> pAtMultiWar(pAtWar.size());

            // the while loop will start another war if previous war ended with multiple players having the highest card
            // aka, multi-war
            while (pAtMultiWar.size() > 1){
                pAtMultiWar.clear();
                rankMax = 0;
                battleWinner = nullptr;
                for (int i = 0; i < pAtWar.size(); i++) {
                    pAtWar[i]->addBattle();

                    // if player cannot continue the war, put all their cards in the warPile
                    if (pAtWar[i]->getNumCards() < 4) {
                        int numDeadCards = pAtWar[i]->getNumCards();
                        for (int j = 0; j < numDeadCards; j++) {
                            warPile.addCard(pAtWar[i]->removeCard());
                        }
                    }
                    else {
                        // each player places 3 cards face down
                        for (int k = 0; k < 3; k++)
                            warPile.addCard(pAtWar[i]->removeCard());
                        // player then puts a card face up for battle
                        Card temp = pAtWar[i]->removeCard();
                        warPile.addCard(temp);
                        cout << "warCard = "; temp.showCard(); cout << endl;

                        if (temp.getValue() > rankMax) {    // check if current player's card is the highest
                            rankMax = temp.getValue();
                            battleWinner = pAtWar[i];
                            pAtMultiWar.clear();   // since this card is the new max, clear the candidates for multi war
                            pAtMultiWar.push_back(pAtWar[i]);
                        }
                        // if the card is the same rank of current highest in play, make them a candidate for multi war
                        else if (temp.getValue() == rankMax) {
                            pAtMultiWar.push_back(pAtWar[i]);
                        }
                    }
                }
                pAtWar.clear();
                for (int x = 0; x < pAtMultiWar.size(); x++)
                    pAtWar.push_back(pAtMultiWar[x]);
            }
        }


        // we have a verdict for the battle/war
        if (battleWinner == nullptr) {    // meaning no players could finish the war...
            for (int i = 0; i < warPile.getNumCards(); i++)
                lostAndFound.addCard(warPile.removeCard());
        }
        else{   // meaning a player won the battle/war
            battleWinner->addWin();
            int cardsInWarPile = warPile.getNumCards();
            for (int i = 0; i < cardsInWarPile; i++)
                battleWinner->addCard(warPile.removeCard());
            int cardsInLF = lostAndFound.getNumCards();
            for (int j = 0; j < cardsInLF; j++)
                battleWinner->addCard(lostAndFound.removeCard());
        }


        cout << "\nBattle " << battleNum << " Stats:" << endl;
        for (int i = 1; i <= players.size(); i++){
            Player p = players[i - 1];
            cout << "Player " << i << ": Fierceness = " << p.getFierceness() << "\tCards = " << p.getNumCards() <<
                     "\tBattles = " << p.getNumBattles() << "\tWon = " << p.getNumWins() << endl;

            }
        battleNum++;


        numPlayersDead = 0;
        int winningPlayer;
        for (int i = 0; i < numPlayers; i++){
            if (players[i].getFierceness() == 0)
                 numPlayersDead++;
            else
                winningPlayer = i + 1;
         }
        if (numPlayersDead == (numPlayers - 1)) {
            cout << "\n================================================" <<
                    "\nWINNER WINNER CHICKEN DINNER - CONGRATS PLAYER "  << winningPlayer << endl;
        }
        else if (numPlayersDead == numPlayers)
            cout << "\n==================================================" <<
                    "\n          There are no winners in war. F         " << endl;
    }


    return 0;

}
