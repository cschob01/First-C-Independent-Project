#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>

#include "card.h"

using namespace std;

class Deck{
    public:
        Deck();
        ~Deck();

        void shuffleDeck();
        void cutDeck();
        Card* getCardPtr(int index);
        char getCardSuit(int index);
        char getCardNumber(int index);

    private:
        Card cards[52];
};




#endif