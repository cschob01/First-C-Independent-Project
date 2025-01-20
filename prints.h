#ifndef PRINTS_H
#define PRINTS_H
#include <iostream>
#include <string>

#include "card.h"
#include "player.h"

using namespace std;

class Prints{
    public:

        void clear();
        void poorInput();
        int shufflePrompt(int round);
        void printStartingSequence();
        void readyPrompt(int i);
        void c_to_continue();

        int bettingDecition1();
        int bettingDecition2(Player players[2], int turn);
        int bettingDecition3(Player players[2], int turn);
        int bettingDecition4(Player players[2], int turn);
        int bettingDecition5(Player players[2], int turn);
        int bettingDecition6(Player players[2], int turn);
        int bettingAmount(Player players[2], int turn);
        int choicePrompt(int choices_allowed);

        void winnerTable(Card * playerCards[2][2], Card * flop[3], Card * turn, Card * river);
        void printWinner(int winner, int pot);
        void printFinalWinner(int gameWinner);
        void printError();

        void printCard1(Card * q);
        void printCard2(Card * q[]);
        void printCard3(Card * q[]);
        void printCard4(Card * q[], Card * r);
        void printCard5(Card * q[], Card * r, Card * t);
        void printStats(int pot, Player players[2]);

        void developerUsePrompt_start(); // Developer access
        void printHighestCards(int highestCards[7]);
        void printHand(bool hand[14][4], int player_number);
        void developerUsePrompt_end(); // Developer access

        string convertInt(int i);
        void printStraightFlush(int winner, int highCard);
        void printQuads(int winner, int quads, int kicker);
        void printFullHouse(int winner, int trips, int pair);
        void printFlush(int winner, bool tie_break, int highCard);
        void printStraight(int winner, int highCard);
        void printTriplePair(int winner, int triPair, int kicker);
        void printDoublePair(int winner, int pair1, int pair2, int kicker);
        void printPair(int winner, int pair, int kicker);
        void printHighCards5(int winner, int kicker);

    private:
};




#endif