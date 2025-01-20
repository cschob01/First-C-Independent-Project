#include <iostream>
#include <string>

#include "player.h"

using namespace std;

Player::Player(){

    this->cash = STARTING_CASH;
    this->commited = 0;

}

Player::~Player(){

}

int Player::getCash(){
    return this->cash;
}

int Player::getCommited(){
    return this->commited;
}

void Player::setCash(int i){
    this->cash = i;
}

void Player::setCommited(int i){
    this->commited = i;
}
