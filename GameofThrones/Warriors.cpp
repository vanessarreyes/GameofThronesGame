// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#include "Warriors.h"

// default constructor
Warriors::Warriors() {
    warrior_name = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    freedom = "yes";
    ship = "no";
    dragonglass = "no";
}

// parameterized constructor
Warriors::Warriors(string name, int s, int l, int m, string f, string boat, string dp) {
    warrior_name = name;
    strength = s;
    loyalty = l;
    morale = m;
    freedom = f;
    ship = boat;
    dragonglass = dp;
}

// returns the warrior's name
string Warriors::getWarriorsName() {
    return warrior_name;
}

// sets the warrior's name
void Warriors::setWarriorsName(string name) {
    warrior_name = name;
}

// returns the warrior's strength
int Warriors::getStrength() {
    return strength;
}

// add or subtracts from the warrior's strength
// true is add
// false is subtract
// limit on strength
void Warriors::setStrength(bool add_sub, int s) {
    if (add_sub = true) {
        if (strength + s > 200) {
            strength = 200;
        }
        else {
            strength = strength + s;
        }
    }
    else {
        if (strength - s < 0) {
            strength = 0;
        }
        else {
            strength = strength - s;
        }
    }
}

// return the warrior's loyalty
int Warriors::getLoyalty() {
    return loyalty;
}

// add or subtract from the warrior's loyalty
// true is add
// false if subtract
// limit on loyalty
void Warriors::setLoyalty(bool add_sub, int l) {
    if (add_sub = true) {
        if (loyalty + l > 100) {
            loyalty = 100;
        }
        else {
            loyalty = loyalty + l;
        }
    }
    else {
        if (loyalty - l < 0) {
            loyalty = 0;
        }
        else {
            loyalty = loyalty - l;
        }
    }
}

// return the warrior's morale 
int Warriors::getMorale() {
    return morale;
}

// addor subtract from the waarrior's morale
// true is add
// false if subtract
// limit on morale
void Warriors::setMorale(bool add_sub, int m) {
    if (add_sub = true) {
        if (morale + m > 100) {
            morale = 100;
        }
        else {
            morale = morale + m;
        }
    }
    else {
        if (morale - m < 0) {
            morale = 0;
        }
        else {
            morale = morale - m;
        }
    }
}

// return if the warrior is free or not
string Warriors::getFree() {
    return freedom;
}

// set if the warrior is free or not
void Warriors::setFree(string y_or_n) {
    if (y_or_n == "yes") {
        freedom = "yes";
    }
    else {
        freedom = "no";
    }
}

// return if the warrior has a ship or not
bool Warriors::getShip() {
    if (ship == "yes") {
        return true;
    }
    else {
        return false;
    }
}

// set or remove a ship to warrior 
void Warriors::setShip(string y_or_n) {
    if (y_or_n == "yes") {
        ship = "yes";
    }
    else {
        ship = "no";
    }
}

// return if the warrior has dragonglass
string Warriors::getDragonglass() {
    return dragonglass;
}

// set dragonglass or remove dragonglass from warrior 
void Warriors::setDragonglass(string y_or_n) {
    if (y_or_n == "yes") {
        dragonglass = "yes";
    }
    else {
        dragonglass = "no";
    }
}

// set the warrior's row
void Warriors::setRow(int r) {
    row = r;
}

// return the warrior's row
int Warriors::getRow() {
    return row;
}

// set the warrior's column
void Warriors::setColumn(int c) {
    column = c;
}

// return the warrior's column
int Warriors::getColumn() {
    return column;
}
