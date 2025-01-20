#include <iostream>
#include <string>

#include "game.h"

using namespace std;

Game::Game(){

    this->round = 1;
    this->dealer = 0;

}

Game::~Game(){
}

void Game::playGame(){

    table.startingSequence();

    while((table.getPlayerCash(0) > 0) & (table.getPlayerCash(1) > 0)){

        table.shuffleSequence(round);

        table.playRound(round);
        round++;

        this->dealer = ((dealer + 1) % 2);
        table.setDealer(dealer);
        
    }
    if(table.getPlayerCash(0) == 0){
        table.printGameWinner(1);
    }
    else if(table.getPlayerCash(1) == 0){
        table.printGameWinner(0);
    }
    else{
        table.printError();
    }
}
