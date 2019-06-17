// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones


#include "Cities.h"

// default constructor
Cities::Cities() {
    letter = "";
    city_name = "";
    money = 0;
    army_size = 0;
    points = 0;
}

// set the letter for that object
void Cities::setLetter(string l) {
    letter = l;
}

// return the letter
string Cities::getLetter() {
    return letter;
}

// set the city's name
void Cities::setCityName(string name) {
    city_name = name;
}

// return the city's name
string Cities::getCityName() {
    return city_name;
}

// set the money value to the city
void Cities::setCityMoney(int m) {
    money = m;
}

// return the money associated with that city
int Cities::getCityMoney() {
    return money;
}

// se the army associated with city
void Cities::setCityArmy(int army) {
    army_size = army;
}

// return the amount of army from that city
int Cities::getCityArmy() {
    return army_size;
}

// set the points associated with that city
void Cities::setCityPoints(int p) {
    points = p;
}

// returnt the points associated with city
int Cities::getCityPoints() {
    return points;
}