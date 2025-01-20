#ifndef Table_H
#define Table_H
#include <iostream>
#include <string>

#include "deck.h"
#include "card.h"
#include "prints.h"
#include "player.h"

using namespace std;

class Table{
    public:
        Table();
        ~Table();

        void setDealer(int dealer);

        Card * getDeckCardPtr(int index);
        void shuffleSequence(int round);
        void startingSequence();

        void playRound(int rounds);
        bool playBets(int table_number);
        int playTurn(int table_number);

        int callBettingDecition(int table_number);

        void printTable(int table_number, int player_number);
        void printGameWinner(int gameWinner);
        void printError();

        void consolidateBets();
        void decideWinner();
        void transferMoney();

        int checkStraightFlush(bool hand1[14][4], bool hand2[14][4]);
        int checkQuads(bool hand1[14][4], bool hand2[14][4]);
        int checkFullHouse(bool hand1[14][4], bool hand2[14][4]);
        int checkFlush(bool hand1[14][4], bool hand2[14][4]);
        int checkStraight(bool hand1[14][4], bool hand2[14][4]);
        int checkTriplePair(bool hand1[14][4], bool hand2[14][4]);
        int checkDoublePair(bool hand1[14][4], bool hand2[14][4]);
        int checkPair(bool hand1[14][4], bool hand2[14][4]);
        int checkHighCards5(bool hand1[14][4], bool hand2[14][4]);

        void initializeHighestCards(bool hand1[14][4], int highestCards[7]);
        void initializeHand(bool hand[14][4], int player_number);

        int findHighestPair(bool hand[14][4], int pair_size, int avoid);
        void findHighestFlush(bool hand[14][4], int flush[5]);
        int findHighestStraight(bool hand[14][4]);
        int findHighestStraightFlush(bool hand[14][4]);
        int findHighestCard(bool hand1[14][4], int place, int avoid1, int avoid2);

        int getPlayerCash(int i);

        static const int SMALL_BLIND = 1;
        static const int BIG_BLIND = 2;

    private:
        Card * flop[3];
        Card * turn;
        Card * river;
        Card * burns[3];

        //First array is PlayerNumber, next is their cards.
        Card * playerCards[2][2];

        int dealer;
        int playerTurn;

        Deck deck;

        Player players[2];

        int pot;
        int winner;

        Prints prints;
};




#endif