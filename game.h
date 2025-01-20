#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>

#include "table.h"

using namespace std;

class Game{
    public:
        Game();
        ~Game();

        void playGame();

    private:
        Table table;
        int round;
        int dealer;
};


#endif