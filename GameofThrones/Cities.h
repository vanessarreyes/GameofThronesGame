// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#ifndef CITIES_H
#define CITIES_H


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


class Cities {
    
    // private data members
    private:
    string letter;
    string city_name;
    int money;
    int army_size;
    int points;
    
    // public data members
    public:
    // default constructor
    Cities();
    void setLetter(string l);
    string getLetter();
    void setCityName(string name);
    string getCityName();
    void setCityMoney(int m);
    int getCityMoney();
    void setCityArmy(int army);
    int getCityArmy();
    void setCityPoints(int p);
    int getCityPoints();
    
    
};



#endif