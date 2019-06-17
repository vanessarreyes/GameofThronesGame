// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#ifndef HEROES_H
#define HEROES_H


#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include "Warriors.h"
using namespace std;

class Heroes {
  
    // private data members
    private:
    string hero_name;
    int money;
    int influence;
    int army_size;
    // array that holds the warriors for the specific hero
    Warriors w_hero[4];
    int row;
    int column;
    string ship;
    // array that holds the land the user controls
    bool control_land[26][16];
    // array that holds the land the user has adventured
    bool adventured[26][16];
    int points;
    
    public:
    //default constructor
    Heroes();
    Heroes(string n, int cash, int i, int a, Warriors w1, Warriors w2, Warriors w3, Warriors w4, int r, int c, string s);
    void setHeroName(string name);
    string getHeroName();
    int getMoney();
    void setMoney(bool add_sub, int amount);
    int getInfluence();
    void setInfluence(bool add_sub, int power);
    int getArmySize();
    void setArmySize(bool add_sub, int people);
    Warriors getCertainWarrior(int num);
    void setWtoH(int r, int c);
    int getNumWarriors();
    void getNamesofWarriors();
    void getHeroesWarriorsPositions();
    void setWarriors(Warriors w);
    void setAddWarriorStrength(int warrior, int n);
    void setAddWarriorMorale(int warrior, int n);
    int getAddWarriorMorale(int warrior);
    void setRow(int r);
    int getRow();
    void setColumn(int c);
    int getColumn();
    bool getShip();
    void setShip(string y_or_n);
    int getPoints();
    void setPoints(bool add_sub, int p);
    bool getControl(int row, int column);
    // find a way to test if the user had control previously
    // add a variable to test the control for this function  
    void setControl(bool control, int row, int column);
    void setAdventured(int row, int column);
    void getControlMap();
    bool getAdventured(int row, int column);
    void setWarriorWithDragonglass(int warrior);
    int getNumControlLand(int hero);
    bool getCheckCity(int r, int c);
    void setDragons(Warriors Dragons);
    void getCheckArya();
    void setArya(Warriors Arya);
    void getLoseJamie();
    void getDrought();
    void getDeserters();
    void getKindness();
    
};

#endif