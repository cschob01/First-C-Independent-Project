#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;


class Card{
    public:
        Card();
        ~Card();

        void setCard(int number, int suit);
        char getSuit();
        char getNumber();
        int getNumber_numberForm();
        int getSuit_numberForm();

    private:
        int number;
        int suit;
};



#endif