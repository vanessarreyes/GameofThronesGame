// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include "Heroes.h"
#include "Warriors.h"
using namespace std;


class Battle {
    // private data members
    private:
    bool winner;
    
    
    // public data members
    public:
    Heroes getSpeech(Heroes h1, Heroes h2);
    Heroes getBuyOut(Heroes h1, Heroes h2);
    Heroes getBattlePlay(Heroes h1, Heroes h2, bool user);
    bool getWinner();

};



#endif