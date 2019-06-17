// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#include "Heroes.h"

// default cnstructor
Heroes::Heroes() {
    // declare variable to empty or starting value 
    hero_name = "";
    money  = 0;
    influence = 0;
    army_size = 0;
    row = 0;
    column = 0;
    ship = "no";
    points = 0;
    // for loop that runs through the two arrays and sets all the values to false
    for (int a = 0; a < 26; a++) {
        for (int i = 0; i < 16; i++) {
            control_land[a][i] = false;
            adventured[a][i] = false;
        }    
    }
}

// parameterized constructor
// used when reading the heroes text file and uses split function to get all variables
Heroes::Heroes(string n, int cash, int i, int a, Warriors w1, Warriors w2, Warriors w3, Warriors w4, int r, int c, string s) {
    hero_name = n;
    money  = cash;
    influence = i;
    army_size = a;
    // add warriors array 
    w_hero[0] = w1;
    w_hero[1] = w2;
    w_hero[2] = w3;
    w_hero[3] = w4;
    row = r;
    column = c;
    // add ship if the user lands on water (only if user makes a character)
    ship = s;
    points = 0;
}

// set the heroes name to input variable
void Heroes::setHeroName(string name) {
    hero_name = name;
}

// returns the hero's name
string Heroes::getHeroName() {
    return hero_name;
}

// get the hero's money
int Heroes::getMoney() {
    return money;
}

// set the hero's money
// send in the money value to add or subtract
// false is to subtract, true is to add
void Heroes::setMoney(bool add_sub, int amount) {
    // check to see if adding money
    if (add_sub == true) {
        money = money + amount; 
    }
    // subtract the money
    else {
        money = money - amount;
    }
}

// return the hero's influence
int Heroes::getInfluence() {
    return influence;
}

// set the hero's influence
// send in the influence amount to add or subtract
// false is to subtract, true is to add
void Heroes::setInfluence(bool add_sub, int power) {
    // checks if need to add
    if (add_sub == true) {
        influence = influence + power; 
    }
    // subtract 
    else {
        influence = influence - power; 
    }
}

//return the army size of the hero
int Heroes::getArmySize() {
    return army_size;
}

// set the army size of the user
// send in the amount to add or subtract to the army
// false is to subtract, true is to add
void Heroes::setArmySize(bool add_sub, int people) {
    // check if to add
    if (add_sub == true) {
        army_size = army_size + people;
    }
    // all else
    else {
        // if that checks to make sure that the army size cannot be negative
        if (army_size - people < 0) {
            army_size = 0;
        }
        // subtract from the army if it is not 0
        else {
            army_size = army_size - people;
        }
    }
}

// return a hero's warrior at a certain position in their warrior array
Warriors Heroes::getCertainWarrior(int warrior) {
    return w_hero[warrior];
}

// set the warrior to the Hero 
// location wise
void Heroes::setWtoH(int r, int c) {
    // for loop that runs through all the hero's warriors
    for (int i = 0; i < 4; i++) {
        // if the warrior name is empty (no warrior there), move onto the next warrior
        if (w_hero[i].getWarriorsName() == "") continue;
        // if that checks if the warrior is not free
        if (w_hero[i].getFree() == "no") {
            // set the warriors row and column to the hero's position
            w_hero[i].setRow(r);
            w_hero[i].setColumn(c);
            // if that checks if the warrior of the hero has a ship
            if (w_hero[i].getShip() == 1) {
                // add a ship to the hero since warrior has a ship
                ship = "yes";
            }
            // TEST
            //cout << w_hero[i].getWarriorsName() << " row is " << w_hero[i].getRow() << " and column is " << w_hero[i].getColumn() << endl;
        }
    }
}

// returns the number of warriors that the hero has
int Heroes::getNumWarriors() {
    // find the number of Warriors in the warrior array and count them
    int count = 0;
    // for loop that runs through all the hero's warriors
    for (int i = 0; i < 4; i++) {
        // if that checks if the warrior is empty and moves onto the next
        if (w_hero[i].getWarriorsName() == "") continue;
        count++;
    }
    // return the amount of warriors
    return count;
}

// function that gets the names of the hero's warriors
void Heroes::getNamesofWarriors() {
    cout << endl;
    cout << "Your Warriors" << endl;
    // if that runs through all the hero's warriors names
    for (int i = 0; i < 4; i++) {
        if (w_hero[i].getWarriorsName() == "") continue;
        cout << "Warrior " << i << " : " << w_hero[i].getWarriorsName() << endl;
    }
}

// function that gets the warriors location
void Heroes::getHeroesWarriorsPositions() {
    for (int i = 0; i < getNumWarriors(); i++) {
        cout << "Location for " << w_hero[i].getWarriorsName() << ": " << "(" << w_hero[i].getRow() << ", " << w_hero[i].getColumn() << ")" << endl;
    }
    
}

// function that sets the next empty position in the warriors array to a new warrior
void Heroes::setWarriors(Warriors warrior) {
    // declare variables
    int place = -1;
    string choice = "";
    int count = 0;
    
    // add the warrior to the next empty array in the Warrior class
    for (int i = 0; i < 4; i++) {
        if (w_hero[i].getWarriorsName() == "") {
            place = i;
            break;
        }
    }
    
    // display the warriors the hero has and ask the hero which of the warriors they
    // want to keep. Replace the not wanted warriors with new ones
    if (place > -1) {
        w_hero[place] = warrior;
        w_hero[place].setFree("no");
    }
    else {
        cout << endl;
        cout << "You cannot carry anymore warriors. Either switch a current warrior for a new one or keep your current." << endl;
        cout << "Here is your current warriors." << endl;
        // for loop that displays the hero's warriors
        for (int i = 0; i < 4; i++) {
            cout << i << ". " << w_hero[i].getWarriorsName() << endl;
        }
        cout << "4. Keep my warriors" << endl;
        cout << endl;
        cout << "You can switch out a warrior for " << warrior.getWarriorsName() << endl;
        cout << "Would you like to replace a warrior? If so, which one?" << endl;
        cin >> choice;
        for (int a = 0; a < choice.length(); a++) {
                while (isalpha(choice[a]) or choice == "") {
                    cout << "Please enter in a value 0-4: ";
                    cin >> choice;
                }
            }
        place = stoi(choice);
        while (place > 4 or column < 0) {
            cout << "Please enter in a value 0-4: ";
            cin >> choice;
            place = stoi(choice);
        }
        
        if (place != 4) {
            w_hero[place] = warrior;
            w_hero[place].setFree("no");
        }
    }
}

// function that adds to the warriors strength
void Heroes::setAddWarriorStrength(int warrior, int num) {
    //cout << "Strength: " << w_hero[warrior].getStrength() << endl; 
    w_hero[warrior].setStrength(true, num);    
    //cout << "New strength: " << w_hero[warrior].getStrength() << endl; 
}

// function thatadds to the warrior's morale
void Heroes::setAddWarriorMorale(int warrior, int num) {
    //cout << "Morale: " << w_hero[warrior].getMorale() << endl; 
    w_hero[warrior].setMorale(true, num);    
    //cout << "New morale: " << w_hero[warrior].getMorale() << endl;     
}

// function that returns the warrior's morale
int Heroes::getAddWarriorMorale(int warrior) {
    return w_hero[warrior].getMorale();
}

// set the hero's row
void Heroes::setRow(int r) {
    row = r;
}

// return the hero's row
int Heroes::getRow() {
    return row;
}

// set the hero's column
void Heroes::setColumn(int c) {
    column = c;
}

// return the hero's column
int Heroes::getColumn() {
    return column;
}

// return if the warrior has a ship or not as true or false
bool Heroes::getShip() {
    if (ship == "yes") {
        return true;
    }
    else {
        return false;
    }
}

// function that changes if the hero has a ship or not 
void Heroes::setShip(string y_or_n) {
    if (y_or_n == "yes") {
        ship = "yes";
    }
    else {
        ship = "no";
    }
}

// return the hero's points
int Heroes::getPoints() {
    return points;
} 

// set the hero's points
// can either subtract or add 
void Heroes::setPoints(bool add_sub, int p) {
    // if that checks if adding
    if (add_sub == true) {
        points = points + p;
    }
    // subtract
    else {
        points = points - p;
    }
}

// return true if the hero has control of a tile
// return false if the hero does not have control of tile
bool Heroes::getControl(int r, int c) {
    return control_land[r][c];
}

// if the hero does not have control of that land tile, then set true for that tile
// if the hero is losing control of a land tile, then set false for that tile
void Heroes::setControl(bool control, int r, int c) {
    if (control == false) {
        control_land[r][c] = true;
    }
    else if (control == true) {
        // depending on the tile that they land on, subtract from the Heroe's points
        // shows that they lost that tile control
        control_land[r][c] = false;
    }
}

// set a position in the adventured array to true (adventured) if the hero has not adventured that area yet
void Heroes::setAdventured(int r, int c) {
    // set the array adventured to true in the column and row
    if (adventured[r][c] == false) {
        adventured[r][c] = true;
    }
    
    //TEST
    // for (int a = 0; a < 25; a++) {
    //         cout << '|';
    //     for (int b = 0; b < 16; b++) {
    //         cout << adventured[a][b] << '|';
    //     }
    //     cout << endl;
    // }
}

//TEST FUNCTION
// function that gets the control map that shows what the hero has control of
void Heroes::getControlMap() {
    for (int a = 0; a < 25; a++) {
            cout << '|';
        for (int b = 0; b < 16; b++) {
            cout << control_land[a][b] << '|';
        }
        cout << endl;
    }
}

// function that finds if the row and column in the map has been adventured by that hero yet
bool Heroes::getAdventured(int r, int c) {
    return adventured[r][c];
}

// function that gives a hero's warrior dragonglass
void Heroes::setWarriorWithDragonglass(int warrior) {
    // if that checks if the warrior does not have dragonglass
    if (w_hero[warrior].getDragonglass() == "no") {
        // if they didn't before, allow warrior to hold the dragonglass
        w_hero[warrior].setDragonglass("yes");
        // ouptut message
        cout << w_hero[warrior].getWarriorsName() << " holds dragonglass now." << endl;
    }
    // if the warrior is already holding dragonglass
    else {
        // declare variables
        string option = "";
        int choice = 0;
        // output message
        cout << w_hero[warrior].getWarriorsName() << " is already holding dragonglass." << endl;
        cout << "Choose another warrior to hold the dragonglass: " << endl;
        
        // for that runs through all the warriors names and ouptuts them
        for (int a = 0; a < getNumWarriors(); a++) {
            if (a == warrior) continue;
            cout << w_hero[a].getWarriorsName() << endl;
        }
        
        // allow user to choose option
        cin >> option;
        // for loop that checks if the user input is a number
        // if not a number, ask the user to keep entering in option
        for (int a = 0; a < option.length(); a++) {
            while (isalpha(option[a])) {
                cout << "Please enter in a value 0-" << getNumWarriors() << ": ";
                cin >> option;
            }
        }
        // convert option to choice
        choice = stoi(option);
        // while loop that runs as long as the choice is not in range
        while (choice > getNumWarriors() or choice < 0) {
            cout << "Please enter in a value 0-" << getNumWarriors() << ": ";
            cin >> option;
            choice = stoi(option);
        }
        // call the function again to test if the new warrior can hold the dragonglass
        setWarriorWithDragonglass(choice);
    }
}

// function that returns the number of control land the hero has
int Heroes::getNumControlLand(int hero) {
    int count = 0;
    
    // nested for loop that runs through the 2D array of control land and tests if that position is true or not
    // if the position is true, add one to the count
    for (int r = 0; r < 26; r++) {
        for (int c = 0; c < 16; c++) {
            if (control_land[r][c] == true) {
                count++;
            }
        }
    }
    // return the count
    return count;
}

// function that checks if the hero has control of a certian city
bool Heroes::getCheckCity(int row, int column) {
    // if that checks if the position is controlled or not
    if (control_land[row][column] == true) {
        // if the user has control of that city, return yes
        return true;    
    }
    else {
        // if they do not have control of that city, return false
        return false;
    }
}

// add a Dragon to the warriors for hero (Daenerys)
void Heroes::setDragons(Warriors Dragons) {
    w_hero[3] = Dragons;
}

// function that checks if the hero has Arya as a warrior and removes her from their array
void Heroes::getCheckArya() {
    string name = "Arya Stark";
    int place = -1;
    
    // for loop that checks if hero has Arya
    for (int i = 0; i < getNumWarriors(); i++) {
        if (w_hero[i].getWarriorsName() == name) {
            w_hero[i].setFree("yes");
            place = i;
            break;
        }   
    }
    
    // if that checks if they do have Arya, to remove her from array
    if (place != -1) {
        // remove Arya from user
        for (int d = place; d < getNumWarriors(); d++) {
            w_hero[d] = w_hero[d+1];
        }
    }
}

// function to set Arya as part of warrior array
void Heroes::setArya(Warriors Arya) {
    int place = -1;
    
    // for that finds an emoty position in warrior array
    for (int i = 0; i < 4; i++) {
        if (w_hero[i].getWarriorsName() == "") {
            place = i;
            break;
        }
    }
    
    // if there is ampty position, set Arya to position
    if (place > -1) {
        w_hero[place] = Arya;
        w_hero[place].setFree("no");
    }
    // else add her to the last positon and replace other warrior
    else {
        w_hero[3] = Arya;
        w_hero[3].setFree("no");
    }
}

// function thatc checks if hero has Jamie and removes him from them
void Heroes::getLoseJamie() {
    Warriors Empty;
    string name = "Jaime Lannister";
    int place = -1;
    
    // for loop that runs through hero's warriors
    for (int i = 0; i < getNumWarriors(); i++) {
        if (w_hero[i].getWarriorsName() == name) {
            w_hero[i].setFree("yes");
            place = i;
            break;
        }   
    }
    
    // if that checks if the user has Jamie and removes him from array
    if (place > -1) {
        for (int d = place; d < getNumWarriors(); d++) {
            // if that makes the last warrior to empty warrior if the hero had 4 warriors previously (prevents same warrior in array)
            if (d == 3 && getNumWarriors() == 4) {
                w_hero[3] = Empty;
            }
            else {
                w_hero[d] = w_hero[d+1];
            }
        }
    }
}

// function that subtracts morale and strength from each hero's warrior to account for drough event
void Heroes::getDrought() {
    for (int i = 0; i < getNumWarriors(); i++) {
        //cout << w_hero[i].getWarriorsName() << " OG Morale: " << w_hero[i].getMorale() << endl;
        w_hero[i].setMorale(false, 10);
        //cout << w_hero[i].getWarriorsName() << "Morale: " << w_hero[i].getMorale() << endl;
        //cout << w_hero[i].getWarriorsName() << " OG Strength: " << w_hero[i].getStrength() << endl;
        w_hero[i].setStrength(false, 10);\
        //cout << w_hero[i].getWarriorsName() << "Strength: " << w_hero[i].getStrength() << endl;
    }
}

// function that subtracts from each hero's warriors loyaty to account for deserters event
void Heroes::getDeserters() {
    for (int i = 0; i < getNumWarriors(); i++) {
        //cout << w_hero[i].getWarriorsName() << " OG Loyalty: " << w_hero[i].getLoyalty() << endl;
        w_hero[i].setLoyalty(false, 10);
        //cout << w_hero[i].getWarriorsName() << " Loyalty: " << w_hero[i].getLoyalty() << endl;
        
    }
}

// function that adds to hero's warriors to account for kindness event
void Heroes::getKindness() {
    for (int i = 0; i < getNumWarriors(); i++) {
        //cout << w_hero[i].getWarriorsName() << " OG Loyalty: " << w_hero[i].getLoyalty() << endl;
        w_hero[i].setLoyalty(true, 10);
        //cout << w_hero[i].getWarriorsName() << " Loyalty: " << w_hero[i].getLoyalty() << endl;
        
    }
}
