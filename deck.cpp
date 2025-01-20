#include <iostream>
#include <string>

#include "deck.h"

using namespace std;

Deck::Deck(){
    int temp_count = 0;
    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 14; j++){
            this->cards[temp_count].setCard(j, i);
            temp_count++;
        }
    }

    //Developer access: print deck
    for(int i; i < 52; i++){
        cout << "Card " << i << ": " << endl;
        cout << "Number: " << cards[i].getNumber() << "  Suit: " << cards[i].getSuit() << endl << endl;
    }
}

Deck::~Deck(){
}

Card* Deck::getCardPtr(int index){
    return &cards[index];
}

void Deck::shuffleDeck(){
    //Create copy
    Card tempCards[52];
    for(int i = 0; i < 52; i++){
        tempCards[i] = cards[i];
    }

    //Tripple shuffle
    for(int i = 0; i < 17; i++){
        cards[3 * i] = tempCards[i];
        cards[(3 * i) + 1] = tempCards[i + 17];
        cards[(3 * i) + 2] = tempCards[i + 34];
    }
    //Bottom card stays at the bottom
}

void Deck::cutDeck(){
    //Create copy
    Card tempCards[52];
    for(int i = 0; i < 52; i++){
        tempCards[i] = cards[i];
    }

    //Cut deck
    for(int i = 20; i < 52; i++){
        cards[i] = tempCards[i-20];
    }
    for(int i = 0; i < 21; i++){
        cards[i] = tempCards[i+31];
    }
}


char Deck::getCardSuit(int index){

    return cards[index].getSuit();

}

char Deck::getCardNumber(int index){

    return cards[index].getNumber();

}