#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

#include "card.h"

using namespace std;

class Player{
    public:
        Player();
        ~Player();

        int getCash();
        int getCommited();
        void setCash(int i);
        void setCommited(int i);

        static const int STARTING_CASH = 1000;

    private:
        int cash;
        int commited;
};


#endif