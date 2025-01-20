#include <iostream>
#include <string>

#include "table.h"

using namespace std;

Table::Table(){

    this->flop[0] = deck.getCardPtr(5);
    this->flop[1] = deck.getCardPtr(6);
    this->flop[2] = deck.getCardPtr(7);

    this->turn = deck.getCardPtr(9);

    this->river = deck.getCardPtr(11);

    this->burns[0] = deck.getCardPtr(4);
    this->burns[1] = deck.getCardPtr(8);
    this->burns[2] = deck.getCardPtr(10);

    this->playerCards[0][0] = deck.getCardPtr(1);
    this->playerCards[1][0] = deck.getCardPtr(2);
    this->playerCards[0][1] = deck.getCardPtr(3);
    this->playerCards[1][1] = deck.getCardPtr(4);

    this->pot = 0;
    this->dealer = 0;
    this->winner = -1;
    this->playerTurn = 0;

}

Table::~Table(){
}

void Table::setDealer(int dealer){
    this->dealer = dealer;
}

Card * Table::getDeckCardPtr(int index){
    return deck.getCardPtr(index);
}

void Table::startingSequence(){
    prints.printStartingSequence();
}

void Table::shuffleSequence(int round){

    prints.clear();
    int choice = 0;
    while(choice != 3){

        choice = prints.shufflePrompt(round);

        prints.clear();

        if(choice == 1){
            deck.shuffleDeck();
        }
        else if(choice == 2){
            deck.cutDeck();
        }
        else if(choice == 456){
            prints.printCard5(flop, turn, river);   //Developer access
        }
        else if(choice == 3){
        }
        else{
            prints.poorInput();
            choice = 2;
        }
    }

}

void Table::printTable(int table_number, int player_number){
    if(table_number == 1){
        prints.printCard3(flop);
    }
    else if(table_number == 2){
        prints.printCard4(flop, turn);
    }
    else if(table_number == 3){
        prints.printCard5(flop, turn, river);
    }

    prints.printCard2(playerCards[player_number]);

    prints.printStats(this->pot, players);

}

void Table::playRound(int rounds){

    bool someone_flopped = false;

    //Set blinds
    players[dealer].setCash(players[dealer].getCash() - SMALL_BLIND);
    players[(dealer + 1) % 2].setCash(players[(dealer + 1) % 2].getCash() - BIG_BLIND);
    players[dealer].setCommited(SMALL_BLIND);
    players[(dealer + 1) % 2].setCommited(BIG_BLIND);

    for(int i = 0; i < 4; i++){
        if(!playBets(i)){
            consolidateBets();
            break;
        }
        consolidateBets();
        if((players[0].getCash() == 0) || (players[1].getCash() == 0)){
            break;
        }
        
    }

    decideWinner();
    transferMoney();
    this->winner = -1;
}

bool Table::playBets(int table_number){

    playerTurn = dealer;

    int not_done = playTurn(table_number);
    if(not_done == 3){
        this->winner = ((playerTurn + 1) % 2);
        return false;
    }

    not_done = 2;

    while(not_done == 2){
        this->playerTurn = ((playerTurn + 1) % 2);
        not_done = playTurn(table_number);
    }

    if(not_done == 3){
        this->winner = ((playerTurn + 1) % 2);
        return false;
    }
    return true;

}

int Table::playTurn(int table_number){
    prints.clear();
    prints.readyPrompt(playerTurn);
    prints.c_to_continue();
    prints.clear();
    printTable(table_number, this->playerTurn);
    int choice = callBettingDecition(table_number);
    if(choice == 1){

        //New_money = Current_money - (opp_commited - my_commited)
        players[playerTurn].setCash(players[playerTurn].getCash() - (players[(playerTurn + 1) % 2].getCommited() - players[playerTurn].getCommited()));
        players[playerTurn].setCommited(players[(playerTurn + 1) % 2].getCommited());
    }
    if(choice == 2){
        int bet = prints.bettingAmount(players, playerTurn);

        //New_money = Current_money - (bet - my_commited)
        players[playerTurn].setCash(players[playerTurn].getCash() - (bet - players[playerTurn].getCommited()));
        players[playerTurn].setCommited(bet);
    }
    if(choice == 3){
    }
    return choice;
}

// Return:
//  1: Check/Call
//  2: Bet/Raise
//  3: Fold
int Table::callBettingDecition(int table_number){
    if(players[(playerTurn + 1) % 2].getCommited() > 0){
        if((players[(playerTurn + 1) % 2].getCommited() == BIG_BLIND) & (players[playerTurn].getCommited() == BIG_BLIND) & (table_number == 0)){
            return prints.bettingDecition5(this->players, this->playerTurn);
        }
        if((players[(playerTurn + 1) % 2].getCommited() == BIG_BLIND) & (table_number == 0)){
            return prints.bettingDecition4(this->players, this->playerTurn);
        }
        if(players[(playerTurn + 1) % 2].getCommited() == (players[playerTurn].getCommited() + players[playerTurn].getCash())){
            return prints.bettingDecition3(this->players, this->playerTurn);
        }
        if(players[(playerTurn + 1) % 2].getCash() == 0){
            return prints.bettingDecition6(this->players, this->playerTurn);
        }
        return prints.bettingDecition2(this->players, this->playerTurn);
    }
    return prints.bettingDecition1();
}

int Table::getPlayerCash(int i){
    return players[i].getCash();;
}

void Table::consolidateBets(){

    for(int i = 0; i < 2; i++){
        this->pot += players[i].getCommited();
        players[i].setCommited(0);
    }

}

void Table::decideWinner(){

    prints.clear();

    bool hand1[14][4];
    bool hand2[14][4];

    initializeHand(hand1, 0);
    initializeHand(hand2, 1);

    if(this->winner == -1){
        prints.winnerTable(playerCards, flop, turn, river);
    }
    if(this->winner == -1){
        this->winner = checkStraightFlush(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkQuads(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkFullHouse(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkFlush(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkStraight(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkTriplePair(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkDoublePair(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkPair(hand1, hand2);
    }
    if(this->winner == -1){
        this->winner = checkHighCards5(hand1, hand2);
    }

    prints.printWinner(this->winner, this->pot);
    prints.c_to_continue();

}

void Table::initializeHand(bool hand[14][4], int player_number){

    for(int i = 0; i < 14; i++){
        for(int k = 0; k < 4; k++){

            hand[i][k] = false;

            if(((playerCards[player_number][0]->getNumber_numberForm() == i + 1) || (playerCards[player_number][0]->getNumber_numberForm() == i - 12)) & (playerCards[player_number][0]->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
            if(((playerCards[player_number][1]->getNumber_numberForm() == i + 1) || (playerCards[player_number][1]->getNumber_numberForm() == i - 12)) & (playerCards[player_number][1]->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
            if(((flop[0]->getNumber_numberForm() == i + 1) || (flop[0]->getNumber_numberForm() == i - 12)) & (flop[0]->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
            if(((flop[1]->getNumber_numberForm() == i + 1) || (flop[1]->getNumber_numberForm() == i - 12)) & (flop[1]->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
            if(((flop[2]->getNumber_numberForm() == i + 1) || (flop[2]->getNumber_numberForm() == i - 12))& (flop[2]->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
            if(((turn->getNumber_numberForm() == i + 1) || (turn->getNumber_numberForm() == i - 12)) & (turn->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
            if(((river->getNumber_numberForm() == i + 1) || (river->getNumber_numberForm() == i - 12)) & (river->getSuit_numberForm() == k + 1)){
                hand[i][k] = true;
            }
        }
    }

    // prints.printHand(hand, player_number);

}

//Check functions return...
// -1: Nothing
// 0: Player 1
// 1: Player 2
// 2: Draw
int Table::checkStraightFlush(bool hand1[14][4], bool hand2[14][4]){

    int player1_highestStraightFlush = findHighestStraightFlush(hand1);
    int player2_highestStraightFlush = findHighestStraightFlush(hand2);

    if((player1_highestStraightFlush == player2_highestStraightFlush) & (player1_highestStraightFlush != 0)){
        prints.printStraightFlush(3, 0);
        return 2;
    }
    if(player1_highestStraightFlush > player2_highestStraightFlush){
        prints.printStraightFlush(1, player1_highestStraightFlush);
        return 0;
    }
    if(player1_highestStraightFlush < player2_highestStraightFlush){
        prints.printStraightFlush(2, player2_highestStraightFlush);
        return 1;
    }

    prints.printStraightFlush(0, 0);
    return -1;

}

int Table::checkQuads(bool hand1[14][4], bool hand2[14][4]){

    int highestQuadPair1 = findHighestPair(hand1, 4, 0);
    int highestQuadPair2 = findHighestPair(hand2, 4, 0);
    int highestCard1 = findHighestCard(hand1, 1, highestQuadPair1, 0);
    int highestCard2 = findHighestCard(hand2, 1, highestQuadPair2, 0);

    if((highestQuadPair1 == highestQuadPair2) & (highestQuadPair1 == 0)){
        prints.printQuads(0, 0, 0);
        return -1;
    }
    if(highestQuadPair1 > highestQuadPair2){
        prints.printQuads(1, highestQuadPair1, 0);
        return 0;
    }
    if(highestQuadPair1 < highestQuadPair2){
        prints.printQuads(2, highestQuadPair2, 0);
        return 1;
    }
    if(highestCard1 > highestCard2){
        prints.printQuads(1, 0, highestCard1);
        return 0;
    }
    if(highestCard1 < highestCard2){
        prints.printQuads(2, 0, highestCard2);
        return 1;
    }
    prints.printQuads(3, 0, 0);
    return 2;

}

int Table::checkFullHouse(bool hand1[14][4], bool hand2[14][4]){

    int highestTriPair1 = findHighestPair(hand1, 3, 0);
    int highestTriPair2 = findHighestPair(hand2, 3, 0);

    int highestPair1 = findHighestPair(hand1, 2, highestTriPair1);
    int highestPair2 = findHighestPair(hand2, 2, highestTriPair2);

    if((highestTriPair1 == 0) & (highestTriPair2 == 0)){
        prints.printFullHouse(0, 0, 0);
        return -1;
    }
    if((highestTriPair1 > highestTriPair2) || ((highestTriPair1 == highestTriPair2) & (highestPair1 > highestPair2))){
        prints.printFullHouse(1, highestTriPair1, highestPair1);
        return 0;
    }
    if((highestTriPair1 < highestTriPair2) || ((highestTriPair1 == highestTriPair2) & (highestPair1 < highestPair2))){
        prints.printFullHouse(2, highestTriPair2, highestPair2);
        return 0;
    }
    prints.printFullHouse(3, 0, 0);
    return 2;
}

int Table::checkFlush(bool hand1[14][4], bool hand2[14][4]){

    int flush1[5];
    int flush2[5];

    findHighestFlush(hand1, flush1);
    findHighestFlush(hand2, flush2);

    for(int i = 0; i < 5; i++){
        if(flush1[i] > flush2[i]){
            if(flush2[i] != 0){
                prints.printFlush(1, false, flush1[i]);
            }
            else{
                prints.printFlush(1, true, flush1[i]);
            }
            return 0;
        }
        if(flush1[i] < flush2[i]){
            if(flush1[i] != 0){
                prints.printFlush(2, false, flush2[i]);
            }
            else{
                prints.printFlush(2, true, flush2[i]);
            }
            return 1;
        }
    }
    if(flush1[2] != 0){
        prints.printFlush(3, false, 0);
        return 2;
    }

    prints.printFlush(0, false, 0);
    return -1;
}

int Table::checkStraight(bool hand1[14][4], bool hand2[14][4]){

    int player1_highestStraight = findHighestStraight(hand1);
    int player2_highestStraight = findHighestStraight(hand2);

    if((player1_highestStraight == player2_highestStraight) & (player1_highestStraight != 0)){
        prints.printStraight(3, 0);
        return 2;
    }
    if(player1_highestStraight > player2_highestStraight){
        prints.printStraight(1, player1_highestStraight);
        return 0;
    }
    if(player1_highestStraight < player2_highestStraight){
        prints.printStraight(2, player2_highestStraight);
        return 1;
    }

    prints.printStraight(0, 0);
    return -1;
}

int Table::checkTriplePair(bool hand1[14][4], bool hand2[14][4]){

    int player1_triPair = findHighestPair(hand1, 3, 0);
    int player2_triPair = findHighestPair(hand2, 3, 0);
    int highestCard11 = findHighestCard(hand1, 1, player1_triPair, 0);
    int highestCard12 = findHighestCard(hand1, 2, player1_triPair, 0);
    int highestCard21 = findHighestCard(hand2, 1, player1_triPair, 0);
    int highestCard22 = findHighestCard(hand2, 2, player1_triPair, 0);

    if(player1_triPair > player2_triPair){
        prints.printTriplePair(1, player1_triPair, 0);
        return 0;
    }
    if(player1_triPair < player2_triPair){
        prints.printTriplePair(2, player2_triPair, 0);
        return 1;
    }
    if(player1_triPair == 0){
        prints.printTriplePair(0, 0, 0);
        return -1;
    }  

    if(highestCard11 > highestCard21){
        prints.printTriplePair(1, 0, highestCard11);
        return 0;
    }
    if(highestCard11 < highestCard21){
        prints.printTriplePair(2, 0, highestCard21);
        return 1;
    }
    if(highestCard12 > highestCard22){
        prints.printTriplePair(1, 0, highestCard12);
        return 0;
    }
    if(highestCard12 < highestCard22){
        prints.printTriplePair(2, 0, highestCard22);
        return 1;
    }

    prints.printTriplePair(3, 0, 0);
    return 2;
}

int Table::checkDoublePair(bool hand1[14][4], bool hand2[14][4]){

    int player1_pair1 = findHighestPair(hand1, 2, 0);
    int player2_pair1 = findHighestPair(hand2, 2, 0);
    int player1_pair2 = findHighestPair(hand1, 2, player1_pair1);
    int player2_pair2 = findHighestPair(hand2, 2, player2_pair1);
    int kicker1 = findHighestCard(hand1, 1, player1_pair1, player1_pair2);
    int kicker2 = findHighestCard(hand2, 1, player2_pair1, player2_pair2);

    if(((player1_pair1 == 0) || ( player1_pair2 == 0)) & ((player2_pair1 == 0) || (player2_pair2 == 0))){
        prints.printDoublePair(0, 0, 0, 0);
        return -1;
    }
    if((player1_pair1 > player2_pair1) || ((player1_pair1 == player2_pair1) & (player1_pair2 > player2_pair2))){
        prints.printDoublePair(1, player1_pair1, player1_pair2, 0);
        return 0;
    }
    if((player1_pair1 < player2_pair1) || ((player1_pair1 == player2_pair1) & (player1_pair2 < player2_pair2))){
        prints.printDoublePair(2, player2_pair1, player2_pair2, 0);
        return 1;
    }
    if(kicker1 > kicker2){
        prints.printDoublePair(1, 0, 0, kicker1);
        return 0;
    }
    if(kicker1 < kicker2){
        prints.printDoublePair(2, 0, 0, kicker2);
        return 1;
    }
    prints.printDoublePair(3, 0, 0, 0);
    return 2;
}

int Table::checkPair(bool hand1[14][4], bool hand2[14][4]){

    int player1_pair = findHighestPair(hand1, 2, 0);
    int player2_pair = findHighestPair(hand2, 2, 0);
    int kickers1[3];
    int kickers2[3];
    for(int i = 0; i < 3; i++){
        kickers1[i] = findHighestCard(hand1, i + 1, player1_pair, 0);
    }
    for(int i = 0; i < 3; i++){
        kickers2[i] = findHighestCard(hand2, i + 1, player2_pair, 0);
    }

    if((player1_pair == 0) & (player2_pair == 0)){
        prints.printPair(0, 0, 0);
        return -1;
    }
    if(player1_pair > player2_pair){
        prints.printPair(1, player1_pair, 0);
        return 0;
    }
    if(player1_pair < player2_pair){
        prints.printPair(2, player2_pair, 0);
        return 1;
    } 
    for(int i = 0; i < 3; i++){
        if(kickers1[i] > kickers2[i]){
            prints.printPair(1, 0, kickers1[i]);
            return 0;
        }
        if(kickers1[i] < kickers2[i]){
            prints.printPair(2, 0, kickers2[i]);
            return 1;
        }
    }

    prints.printPair(3, 0, 0);
    return 2;

}

int Table::checkHighCards5(bool hand1[14][4], bool hand2[14][4]){

    int highestCards1[7];
    int highestCards2[7];
    initializeHighestCards(hand1, highestCards1);
    initializeHighestCards(hand2, highestCards2);

    for(int i = 0; i < 5; i++){
        if(highestCards1[i] > highestCards2[i]){
            prints.printHighCards5(1, highestCards1[i]);
            return 0;
        }
        if(highestCards1[i] < highestCards2[i]){
            prints.printHighCards5(2, highestCards2[i]);
            return 1;
        }
    }

    prints.printHighCards5(3, 0);
    return 2;
}

int Table::findHighestStraightFlush(bool hand[14][4]){
    
    int temp_count = 0;

    for(int i = 0; i < 4; i++){
        for(int k = 13; k > -1; k--){
            if(hand[k][i]){
                temp_count++;
                if(temp_count == 5){
                    return k + 5;
                }
            }
            else{
                temp_count = 0;
            }
        }
        temp_count = 0;
    }

    return 0;
}

void Table::findHighestFlush(bool hand[14][4], int flush[5]){

    for(int i = 0; i < 5; i++){
        flush[i] = 0;
    }

    int temp_count = 0;

    for(int i = 0; i < 4; i++){
        for(int k = 13; k > 0; k--){
            if(hand[k][i]){
                flush[temp_count] = k + 1;
                temp_count++;
                if(temp_count == 5){
                    break;
                }
            }
        }
        if(temp_count == 5){
            break;
        }
        for(int i = 0; i < 5; i++){
            flush[i] = 0;
        }
        temp_count = 0;
    }
}

int Table::findHighestStraight(bool hand[14][4]){
    
    bool found = false;
    int temp_count = 0;
    
    for(int i = 13; i > -1; i--){
        for(int k = 0; k < 4; k++){
            if(hand[i][k]){
                found = true;
            }
        }
        if(found){
            temp_count++;
            if(temp_count == 5){
                return i + 5;
            }
        }
        else{
            temp_count = 0;
        }
        found = false;
    }

    return 0;
}

int Table::findHighestPair(bool hand[14][4], int pair_size, int avoid){

    int temp_count = 0;

    for(int i = 13; i > 0; i--){
        if((i + 1) == avoid){
            continue;
        }
        for(int k = 0; k < 4; k++){
            if(hand[i][k]){
                temp_count++;
            }
            if(temp_count == pair_size){
                return i + 1;
            }
        }
        temp_count = 0;
    }

    return 0;
}

int Table::findHighestCard(bool hand1[14][4], int place, int avoid1, int avoid2){

    int highestCards[7];
    initializeHighestCards(hand1, highestCards);

    int unique_card_count = 1;

    for(int i = 0; i < 7; i++){
        if((highestCards[i] != avoid1) & (highestCards[i] != avoid2)){
            if(unique_card_count == place){
                return highestCards[i];
            }
            unique_card_count++;
        }
    }

    cout << "ERROR IN findHighestCard!!!" << endl;
    return -1;
}

void Table::initializeHighestCards(bool hand[14][4], int highestCards[7]){

    for(int i = 0; i < 7; i++){
        highestCards[i] = 0;
    }

    int temp_count = 0;
    for(int i = 13; i > 0; i--){
        for(int k = 0; k < 4; k++){
            if(hand[i][k]){
                highestCards[temp_count] = i + 1;
                temp_count++;
            }
        }
    }

    // prints.printHighestCards(highestCards);
}

void Table::transferMoney(){
    
    if(this->winner == 2){
        players[0].setCash(players[0].getCash() + (this->pot/2));
        players[1].setCash(players[1].getCash() + (this->pot/2));
    }
    else{
        players[winner].setCash(players[winner].getCash() + this->pot);
    }
    this->pot = 0;

}

void Table::printGameWinner(int gameWinner){
    prints.printFinalWinner(gameWinner);
}

void Table::printError(){
    prints.printError();
}