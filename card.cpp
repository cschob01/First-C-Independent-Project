#include <iostream>
#include <string>

#include "card.h"

using namespace std;

Card::Card(){

    this->number = 0;
    this->suit = 0;

}

Card::~Card(){
}

void Card::setCard(int number, int suit){

    this->number = number;
    this->suit = suit;

}

char Card::getSuit(){
    if(this->suit == 1){
        return 'C';
    }
    if(this->suit == 2){
        return 'H';
    }
    if(this->suit == 3){
        return 'S';
    }
    if(this->suit == 4){
        return 'D';
    }
    return 'X';
}

char Card::getNumber(){
    if((this->number <= 9) & (this->number != 1)){
        return this->number + 48;
    }
    else if(this->number == 1){
        return 'A';
    }
    else if(this->number == 13){
        return 'K';
    }
    else if(this->number == 12){
        return 'Q';
    }
    else if(this->number == 11){
        return 'J';
    }
    else if(this->number == 10){
        return 'T';
    }
    return 'X';
}

int Card::getSuit_numberForm(){
    return this->suit;
}

int Card::getNumber_numberForm(){
    return this->number;
}