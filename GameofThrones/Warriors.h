// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#ifndef WARRIORS_H
#define WARRIORS_H

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
using namespace std;

class Warriors {
    // private data members
    private:
    // declare variables
    string warrior_name;
    int strength;
    int loyalty;
    int morale;
    string freedom;
    string ship;
    string dragonglass;
    int row;
    int column;
    
    // public data members
    public:
    // default constructor
    Warriors();
    // paramaterized constructor
    Warriors(string name, int s, int l, int m, string f, string boat, string dp);
    string getWarriorsName();
    void setWarriorsName(string name);
    int getStrength();
    void setStrength(bool add_sub, int s);
    int getLoyalty();
    void setLoyalty(bool add_sub, int l);
    int getMorale();
    void setMorale(bool add_sub, int m);
    string getFree();
    void setFree(string y_or_n);
    bool getShip();
    void setShip(string y_or_n);
    string getDragonglass();
    void setDragonglass(string y_or_n);
    void setRow(int r);
    int getRow();
    void setColumn(int c);
    int getColumn();
};




#endif