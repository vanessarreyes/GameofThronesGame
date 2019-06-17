// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#ifndef GAMEPLAY_H
#define GAMEPLAY_H


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
#include <vector>
#include "Warriors.h"
#include "Cities.h"
#include "Heroes.h"
#include "Battle.h"
using namespace std;


class gamePlay {
  
    // private data members
    private:
    // array that holds all the heroes in game
    Heroes h[7];
    // array that holds all the warriors in the game
    Warriors w[14];
    // array that holds map with 25 columns and 16 rows
    string map[25][16];
    // array that holds the dragonglass locations
    bool dp_locations[25][16];
    // array that holds all the cities
    Cities c[26];
    // object of Battle class
    Battle b;
    // declare variables
    int row;
    int column;
    bool lost_or_win;
    int numWarriors;
    int numHeroes;
    int turns;
    string usersHeroName;
    int deny;
    
    
    public:
    // default constructor
    gamePlay();
    // upload text file to enter in heroes
    void getHeroes(string hero_file);
    // upload text file to enter in warriors
    void getWarriors(string warrior_file);
    // function to get number of heroes in game
    int getNumHeroes();
    // set the number of heroes in the game
    void setNumHeroes(int num);
    // get the number of warriors in the game
    int getNumWarriors();
    // set the number of warriors in the game
    void setNumWarriors(int n);
    // if the user makes a hero, set variables to a new object in last position of array
    void setUserHero(string name, int money, int influence, int army, int row, int column);
    // set the warriors to the heroes location
    void setWarriorsToHeroLocation();
    void getUpdateWarriors();
    void setFreeWarriors();
    void getMap(string map_file);
    void getCitiesInfo(string cities_file);
    // determines tile hero is at and adds points needed 
    void getLocationPoints();
    void getMiniMap(int hero_num);
    void getCheckNearWarriors(int hero_num);
    void getSurroundings(int hero_num);
    void getCheckOthersSurroundings(int hero);
    void getNewLocationResources(int user_place);
    void getCheckDragonglass(int user_num);
    void getTravel(int hero_num);
    void getRest(int hero_num);
    void getGodTalk(int hero_num);
    void getMovePlayers(int hero_num);
    void getMoveHeroesLocation(int hero);
    void getMoveWarriorsLocation(int warrior);
    void getRandomEvent(int hero_num);
    void getSetEvents(int hero_num);
    void getWhiteWalkers(int hero_num);
    void setContinueGame(bool w_l);
    bool getContinueGame();
    void getRecordGame(int hero, bool self, string user_name, string file);
    void setTurns();
    int getTurns();
    int getUserNum(int user);
    void setUsersHeroName(int hero_num);
    int getUsersHeroPosition();
};

#endif