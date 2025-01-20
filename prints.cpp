#include <iostream>
#include <string>

#include "prints.h"

using namespace std;


void Prints::clear(){
    for(int i = 0; i < 70; i++){
        cout << endl;
    }
}

int Prints::shufflePrompt(int round){
    cout << "Shuffle the deck." << endl << endl;
    cout << "1: Shuffle" << endl;
    cout << "2: Cut" << endl;
    cout << "3: Continue to round " << round << endl;
    cout << endl << "Choice: ";

    int choice = 0;
    cin >> choice;

    return choice;
}

void Prints::printStartingSequence(){
    clear();
    cout << "This is two-player pass-and-play Heads Up Poker." << endl << endl;
    cout << "Programed in c++ by Carlos Schober using visual studio." << endl;
    cout << "Special thanks to Pablo Schober." << endl << endl;
    c_to_continue();
}

void Prints::poorInput(){
    cout << "You did not input a valid choice." << endl << endl;
}

void Prints::printCard1(Card * q){

    char q_n = q->getNumber();
    char q_s = q->getSuit();

}

void Prints:: printCard2(Card * q[]){

    char q_n = q[0]->getNumber();
    char q_s = q[0]->getSuit();

    char w_n = q[1]->getNumber();
    char w_s = q[1]->getSuit();

    cout << "   _______________          _______________       " << endl;
    cout << "  /               \\        /               \\    " << endl;
    cout << " |  " << q_s << "              |      |  " << w_s << "              |     " << endl;
    cout << " |                 |      |                 |     " << endl;
    cout << " |                 |      |                 |     " << endl;
    cout << " |        " << q_n << "        |      |        " << w_n << "        |     " << endl;
    cout << " |                 |      |                 |     " << endl;
    cout << " |                 |      |                 |     " << endl;
    cout << " |                 |      |                 |     " << endl;
    cout << " |              " << q_s << "  |      |              " << w_s << "  |     " << endl;
    cout << "  \\_______________/        \\_______________/    " << endl;


}

void Prints::printCard3(Card * q[]){

    char q_n = q[0]->getNumber();
    char q_s = q[0]->getSuit();

    char w_n = q[1]->getNumber();
    char w_s = q[1]->getSuit();

    char e_n = q[2]->getNumber();
    char e_s = q[2]->getSuit();

    cout << "   _______________          _______________          _______________    " << endl;
    cout << "  /               \\        /               \\        /               \\   " << endl;
    cout << " |  " << q_s << "              |      |  " << w_s << "              |      |  " << e_s << "              |   " << endl;
    cout << " |                 |      |                 |      |                 |  " << endl;
    cout << " |                 |      |                 |      |                 |  " << endl;
    cout << " |        " << q_n << "        |      |        " << w_n << "        |      |        " << e_n << "        |   " << endl;
    cout << " |                 |      |                 |      |                 |  " << endl;
    cout << " |                 |      |                 |      |                 |  " << endl;
    cout << " |                 |      |                 |      |                 |  " << endl;
    cout << " |              " << q_s << "  |      |              " << w_s << "  |      |              " << e_s << "  |   " << endl;
    cout << "  \\_______________/        \\_______________/        \\_______________/   " << endl;


}

void Prints:: printCard4(Card * q[], Card * r){

    char q_n = q[0]->getNumber();
    char q_s = q[0]->getSuit();

    char w_n = q[1]->getNumber();
    char w_s = q[1]->getSuit();

    char e_n = q[2]->getNumber();
    char e_s = q[2]->getSuit();

    char r_n = r->getNumber();
    char r_s = r->getSuit();

    cout << "   _______________          _______________          _______________          _______________    " << endl;
    cout << "  /               \\        /               \\        /               \\        /               \\    " << endl;
    cout << " |  " << q_s << "              |      |  " << w_s << "              |      |  " << e_s << "              |      |  " << r_s << "              |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |  " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |  " << endl;
    cout << " |        " << q_n << "        |      |        " << w_n << "        |      |        " << e_n << "        |      |        " << r_n << "        |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |  " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |  " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |  " << endl;
    cout << " |              " << q_s << "  |      |              " << w_s << "  |      |              " << e_s << "  |      |              " << r_s << "  |   " << endl;
    cout << "  \\_______________/        \\_______________/        \\_______________/        \\_______________/    " << endl;


}

void Prints:: printCard5(Card * q[], Card * r, Card * t){

    char q_n = q[0]->getNumber();
    char q_s = q[0]->getSuit();

    char w_n = q[1]->getNumber();
    char w_s = q[1]->getSuit();

    char e_n = q[2]->getNumber();
    char e_s = q[2]->getSuit();

    char r_n = r->getNumber();
    char r_s = r->getSuit();

    char t_n = t->getNumber();
    char t_s = t->getSuit();


    cout << "   _______________          _______________          _______________          _______________          _______________     " << endl;
    cout << "  /               \\        /               \\        /               \\        /               \\        /               \\    " << endl;
    cout << " |  " << q_s << "              |      |  " << w_s << "              |      |  " << e_s << "              |      |  " << r_s << "              |      |  " << t_s << "              |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |      |                 |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |      |                 |   " << endl;
    cout << " |        " << q_n << "        |      |        " << w_n << "        |      |        " << e_n << "        |      |        " << r_n << "        |      |        " << t_n << "        |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |      |                 |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |      |                 |   " << endl;
    cout << " |                 |      |                 |      |                 |      |                 |      |                 |   " << endl;
    cout << " |              " << q_s << "  |      |              " << w_s << "  |      |              " << e_s << "  |      |              " << r_s << "  |      |              " << t_s << "  |   " << endl;
    cout << "  \\_______________/        \\_______________/        \\_______________/        \\_______________/        \\_______________/    " << endl;


}

void Prints::printStats(int pot, Player players[2]){

    cout << endl;
    cout << "       Cash:" << endl;
    cout << "         Player 1: " << players[0].getCash() << "$" << endl;
    cout << "         Player 2: " << players[1].getCash() << "$" << endl;
    cout << endl;
    cout << "       Commited:" << endl;
    cout << "         Player 1: " << players[0].getCommited() << "$" << endl;
    cout << "         Player 2: " << players[1].getCommited() << "$" << endl;
    cout << "         Pot: " << pot << "$" << endl;
    cout << endl;

}

void Prints::readyPrompt(int i){
    cout << "Player " << i + 1 << ": Ready?" << endl << endl;
}

void Prints:: c_to_continue(){
    cout << "Type c to continue: ";
    string skip;
    cin >> skip;
}

int Prints::bettingDecition1(){

    cout << endl << endl << "1: Check";
    cout << endl << "2: Bet";
    cout << endl << "3: Fold" << endl;
    
    return choicePrompt(3);

}

int Prints::bettingDecition2(Player players[2], int turn){

    cout << endl << endl << "1: Call " << players[(turn + 1) % 2].getCommited() << "$ (add " << players[(turn + 1) % 2].getCommited() - players[(turn) % 2].getCommited() << "$)";
    cout << endl << "2: Re-raise";
    cout << endl << "3: Fold" << endl;
    
    return choicePrompt(3);

}

int Prints::bettingDecition3(Player players[2], int turn){

    cout << endl << endl << "1: All in for " << players[(turn + 1) % 2].getCommited() << "$ (add " << players[(turn + 1) % 2].getCommited() - players[(turn) % 2].getCommited() << "$)";
    cout << endl << "2: Fold" << endl;
    
    return choicePrompt(2);

}

int Prints::bettingDecition5(Player players[2], int turn){

    cout << endl << endl << "1: Check";
    cout << endl << "2: Bet";
    cout << endl << "3: Fold" << endl;
    
    return choicePrompt(3);

}

int Prints::bettingDecition4(Player players[2], int turn){

    cout << endl << endl << "1: Call " << players[(turn + 1) % 2].getCommited() << "$ (add " << players[(turn + 1) % 2].getCommited() - players[(turn) % 2].getCommited() << "$)";
    cout << endl << "2: Raise";
    cout << endl << "3: Fold" << endl;

    return choicePrompt(3);
}

int Prints::bettingDecition6(Player players[2], int turn){

    cout << endl << endl << "1: Call " << players[(turn + 1) % 2].getCommited() << "$ (add " << players[(turn + 1) % 2].getCommited() - players[(turn) % 2].getCommited() << "$)";
    cout << endl << "2: Fold" << endl;
    
    int choice = choicePrompt(2);

    if(choice == 2){
        return 3;
    }
    else{
        return 1;
    }
}

int Prints::choicePrompt(int choices_allowed){
    int choice = 0;
    while(true){
        cout << endl << "Choice: ";
        cin >> choice;
        for(int i = 1; i <= choices_allowed; i++){
            if(choice == i){
                return choice;
            }
        }
        cout << endl << "Invalid choice" << endl;
    }
}

//Simply returns betting amount
int Prints::bettingAmount(Player players[2], int turn){

    int bet = 0;
    bool not_done = true;

    while(not_done){

        cout << endl << "Dollar amount you wish to bet: ";
        cin >> bet;

        if((bet > players[(turn + 1) % 2].getCommited())
        & (bet <= players[turn].getCash() + players[turn].getCommited())
        & (bet <= players[(turn + 1) % 2].getCash() + players[(turn + 1) % 2].getCommited())){
            not_done = false;
        }
        else{
            cout << endl << "Invalid bet" << endl;
        }

    }

    return bet;

}

void Prints::winnerTable(Card * playerCards[2][2], Card * flop[3], Card * turn, Card * river){
    printCard5(flop, turn, river);
    cout << endl << "Player 1:" << endl;
    printCard2(playerCards[0]);
    cout << endl << "Player 2:" << endl;
    printCard2(playerCards[1]);
}

void Prints::printWinner(int winner, int pot){

    if(winner == 2){
        cout << endl;
        cout << "All bets returned" << endl;
        cout << endl;
    }
    else{
        cout << endl;
        cout << "PLAYER " << (winner + 1) << " WINS " << pot << "$ !!!" << endl;
        cout << endl;
    }

}

string Prints::convertInt(int i){
    if(i == 1){
        return "ace";
    }
    if(i == 2){
        return "two";
    }
    if(i == 3){
        return "three";
    }
    if(i == 4){
        return "four";
    }
    if(i == 5){
        return "five";
    }
    if(i == 6){
        return "six";
    }
    if(i == 7){
        return "seven";
    }
    if(i == 8){
        return "eight";
    }
    if(i == 9){
        return "nine";
    }
    if(i == 10){
        return "ten";
    }
    if(i == 11){
        return "jack";
    }
    if(i == 12){
        return "queen";
    }
    if(i == 13){
        return "king";
    }
    if(i == 14){
        return "ace";
    }
    return "weird card";
}

void Prints::printHighestCards(int highestCards[7]){
    developerUsePrompt_start();
    cout << endl;
    cout << "Highest Cards:";
    for(int i = 0; i < 7; i++){
        cout << "    " << highestCards[i];
    }
    cout << endl << endl;;
    developerUsePrompt_end();
}

void Prints::printHand(bool hand[14][4], int player_number){
    developerUsePrompt_start();

    cout << "Player " << player_number + 1 << "'s Hand:" << endl << endl;
    cout << "              1     2     3     4     5     6     7     8     9     T     J     Q     K     A     " << endl;
    cout << endl;
    cout << "Clubs:        " << hand[0][0] << "     " << hand[1][0] << "     " << hand[2][0] << "     " << hand[3][0] << "     " << hand[4][0] << "     " << hand[5][0] << "     " << hand[6][0] << "     " << hand[7][0] << "     " << hand[8][0] << "     " << hand[9][0] << "     " << hand[10][0] << "     " << hand[11][0] << "     " << hand[12][0] << "     " << hand[13][0] << "     " << endl;
    cout << endl;
    cout << "Hearts:       " << hand[0][1] << "     " << hand[1][1] << "     " << hand[2][1] << "     " << hand[3][1] << "     " << hand[4][1] << "     " << hand[5][1] << "     " << hand[6][1] << "     " << hand[7][1] << "     " << hand[8][1] << "     " << hand[9][1] << "     " << hand[10][1] << "     " << hand[11][1] << "     " << hand[12][1] << "     " << hand[13][1] << "     " << endl;
    cout << endl;
    cout << "Spades:       " << hand[0][2] << "     " << hand[1][2] << "     " << hand[2][2] << "     " << hand[3][2] << "     " << hand[4][2] << "     " << hand[5][2] << "     " << hand[6][2] << "     " << hand[7][2] << "     " << hand[8][2] << "     " << hand[9][2] << "     " << hand[10][2] << "     " << hand[11][2] << "     " << hand[12][2] << "     " << hand[13][2] << "     " << endl;
    cout << endl;
    cout << "Diamonds:     " << hand[0][3] << "     " << hand[1][3] << "     " << hand[2][3] << "     " << hand[3][3] << "     " << hand[4][3] << "     " << hand[5][3] << "     " << hand[6][3] << "     " << hand[7][3] << "     " << hand[8][3] << "     " << hand[9][3] << "     " << hand[10][3] << "     " << hand[11][3] << "     " << hand[12][3] << "     " << hand[13][3] << "     " << endl;

    developerUsePrompt_end();
}

void Prints::developerUsePrompt_start(){
    cout << "-----------------------------------" << endl;
    cout << "       FOR DEVELOPER USE ONLY     " << endl;
    cout << endl;
}

void Prints::developerUsePrompt_end(){
    cout << endl;
    cout << "       FOR DEVELOPER USE ONLY     " << endl;
    cout << "-----------------------------------" << endl;
}

void Prints::printStraightFlush(int winner, int highCard){

    cout << "Straight flushes: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printQuads(int winner, int quads, int kicker){

    cout << "Quads: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printFullHouse(int winner, int trips, int pair){

    cout << "Full houses: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printFlush(int winner, bool tie_break, int highCard){

    cout << "Flushes: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printStraight(int winner, int highCard){

    cout << "Straights: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }
    

}
void Prints::printTriplePair(int winner, int triPair, int kicker){

    cout << "Trips: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printDoublePair(int winner, int pair1, int pair2, int kicker){

    cout << "Double pairs: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printPair(int winner, int pair, int kicker){

    cout << "Pairs: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}
void Prints::printHighCards5(int winner, int kicker){

    cout << "Highest cards: ";
    if(winner == 0){
        cout << "None" << endl;
    }
    if(winner == 3){
        cout << "Draw" << endl;
    }
    if((winner == 1) || (winner == 2)){
        cout << "Player " << winner << " wins" << endl;
    }

}

void Prints::printFinalWinner(int gameWinner){
    cout << endl;
    cout << "Player " << gameWinner + 1 << " wins heads up!" << endl;
    cout << endl;
}

void Prints::printError(){
    cout << "--------------------" << endl;
    cout << endl;
    cout << "Something went wrong" << endl;
    cout << endl;
    cout << "--------------------" << endl;
}