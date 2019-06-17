// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#include "gamePlay.h"

// default constructor
gamePlay::gamePlay() {
    numWarriors = 0;
    for (int r = 0; r < 25; r++) {
        for (int c = 0; c < 16; c++) {
            dp_locations[r][c] = false;
        }    
    }
    lost_or_win = true;
    numHeroes = 0;
    numWarriors = 0;
    turns = 0;
    deny = 0;
}

/*
    - function that reads a text file and gets all the hero's information
    
    - opens the file and reads the text inside
    - adds a comma to the end of each line to show seperation
    - uses a for loop to read through the string variable and split the words up at each time it runs through a comma
    - takes the string word that it split and enters it as a variable of a hero in the array 
    - once the for loop runs through the last part of each text line in the string, it will move onto the next hero in the array to enter in that hero's data
    
    - returns: nothing
    - output: nothing
*/
void gamePlay::getHeroes(string file_name) {
    // declare variables
    string name = "";
    int money = 0;
    int influence = 0;
    int army = 0;
    Warriors w_hero_1;
    Warriors w_hero_2;
    Warriors w_hero_3;
    Warriors w_hero_4;
    int row = 0;
    int column = 0;
    string ship = "";
    int count = 0;
    int hero = 0;
    int place = -1;
    
    // create an ouput file stream for writing to file
    ifstream myfile;
    
    // open the file with the file stream
    myfile.open(file_name);
    // declare variables
    string line = "";
    string word = "";
    char comma = ',';
    char dash = '/';
    
    
    // if statement that checks if text file is open
    if (myfile.is_open()) {
        // while loop that runs through each line of text file
        while (getline(myfile, line)) {
            
            // if statement that checks if the line is empty and to move onto next line
            if (line.empty()) continue;
            
            // add a comma to the end of each line to show different lines from text
            line = line + comma;
            // for loop that runs through each variable in line string
            for (int i = 0; i < line.length(); i++) {
                // if statement that checks if the char in line is equal to a comma
                if (line[i] == comma) {
                    // switch case that enters the variable into a setter of the hero function depending on
                    // count variable
                    switch (count) {
                        // case 0 is to set hero's name 
                        case 0:
                            name = word;
                            // add the hero's name
                            h[hero].setHeroName(name);
                            //TEST
                            //cout << h[hero].getHeroName() << endl;
                            //
                            word = "";
                            // add to the count 
                            count++;
                            break;
                        // case 1 is to set the amount of money for that hero
                        case 1:
                        // if that checks if the string is empty
                            if (!word.empty()) {
                                money = stoi(word);
                            }
                            // add the money to the hero
                            h[hero].setMoney(true, money);
                            // TEST
                            //cout << h[hero].getMoney() << endl;
                            //
                            word = "";
                            count++;
                            break;
                        // case 2 is to se the hero's influence
                        case 2:
                        // if that checks if the word is empty
                            if (!word.empty()) {
                                influence = stoi(word);
                            }
                            // add the influence to the hero
                            h[hero].setInfluence(true, influence);
                            // TEST
                            //cout << h[hero].getInfluence() << endl;
                            //
                            word = "";
                            count++;
                            break;
                        // case 3 that adds the hero's army size
                        case 3:
                        // if that checks if the word is empty
                            if (!word.empty()) {
                                army = stoi(word);
                            }
                            // add the hero's army
                            h[hero].setArmySize(true, army);
                            // TEST
                            //cout << h[hero].getArmySize() << endl;
                            //
                            word = "";
                            count++;
                            break;
                        // case 4 that sets the hero's first warrior 
                        case 4:
                        // if that checks if there is a not a warrior (NULL type)
                            if (word == "NULL") {
                                word = "";
                                count++;
                                break;
                            }
                            // all else (if there is a warrior)
                            else {
                                // TEST
                                // cout << "Name: " << word << endl; 
                                //
                                place = -1;
                                
                                // for loop that checks where the next empty position is in the warrior's array and takes that position number
                                for (int i = 0; i < numWarriors; i++) {
                                    // if that checks if the warrior's name matches with the array of warriors
                                    // find the warrior in the main game array and se that position to update warrior's vatables for hero
                                    if (word == w[i].getWarriorsName()) {
                                        // set place to position of array
                                        place = i;
                                        break;
                                    }
                                }
                                // set the warrior object to the hero's first warrior object
                                w_hero_1 = w[place];
                                // add the warrior to the warrior's array for hero's
                                h[hero].setWarriors(w_hero_1);
                                word = "";
                                count++;
                                break;
                            }
                        // case 5 that sets the hero's second warrior
                        case 5:
                        // if that checks if there is a warrior to set (NULL type)
                            if (word == "NULL") {
                                word = "";
                                count++;
                                break;
                            }
                            // all else (there is warrior)
                            else {
                                place = -1;
                                // for loop that runs through warrior array to find next empty position
                                for (int i = 0; i < numWarriors; i++) {
                                    // if that checks if the warrior's name matches with the array of warriors
                                    // find the warrior in the main game array and se that position to update warrior's vatables for hero
                                    if (word == w[i].getWarriorsName()) {
                                        // set the next empty position to place
                                        place = i;
                                        break;
                                    }
                                }
                                // set the warrior object to the hero's second warrior object
                                w_hero_2 = w[place];
                                // add the warrior to the warrior's array for hero's
                                h[hero].setWarriors(w_hero_2);
                                word = "";
                                count++;
                                break;
                            }
                        // case 6 that sets the hero's third warrior
                        case 6:
                            // if that checks if there is a not a warrior (NULL type)
                            if (word == "NULL") {
                                count++;
                                word = "";
                                break;
                            }
                            // all else (there is warrior)
                            else {
                                place = -1;
                                // for loop that runs through warrior array to find next empty position
                                for (int i = 0; i < numWarriors; i++) {
                                    // if that checks if the warrior's name matches with the array of warriors
                                    // find the warrior in the main game array and se that position to update warrior's vatables for hero
                                    if (word == w[i].getWarriorsName()) {
                                        place = i;
                                        break;
                                    }
                                }
                                // set the warrior object to the hero's third warrior object
                                w_hero_3 = w[place];
                                // add the warrior to the warrior's array for hero's
                                h[hero].setWarriors(w_hero_3);
                                word = "";
                                count++;
                                break;
                            }
                        // case 7 that sets the hero's fourth warrior
                        case 7:
                            // if that checks if there is a not a warrior (NULL type)
                            if (word == "NULL") {
                                count++;
                                word = "";
                                break;
                            }
                            // all else (there is warrior)
                            else {
                                place = -1;
                                // for loop that runs through warrior array to find next empty position
                                for (int i = 0; i < numWarriors; i++) {
                                    // if that checks if the warrior's name matches with the array of warriors
                                    // find the warrior in the main game array and se that position to update warrior's vatables for hero
                                    if (word == w[i].getWarriorsName()) {
                                        place = i;
                                        break;
                                    }
                                }
                                // set the warrior object to the hero's fourth warrior object
                                w_hero_4 = w[place];
                                // add the warrior to the warrior's array for hero's
                                h[hero].setWarriors(w_hero_4);
                                word = "";
                                count++;
                                break;
                            }
                        // case 8 that sets the hero's row value
                        case 8:
                            // if that checks if the word is empty
                            if (!word.empty()) {
                                // subtract one to account for array position
                                // convert to integer
                                row = stoi(word) - 1;
                            }
                            // set the hero's row
                            h[hero].setRow(row);
                            // cout << "Row: " << h[hero].getRow() << endl;
                            word = "";
                            count++;
                            break;
                        // case 9 that sets the hero's column
                        case 9:
                            // if that checks if the word is empty
                            if (!word.empty()) {
                                // subtract one to account for array position
                                column = stoi(word) - 1;
                            }
                            // set the hero's column 
                            h[hero].setColumn(column);
                            // cout << "Column: " << h[hero].getColumn() << endl;
                            word = "";
                            count++;
                            break;
                        // case 10 that sets if the hero has a ship or not
                        case 10:
                            ship = word;
                            // if that takes the /n away from the end of the string 
                            if (hero < 5) {
                                ship.erase(ship.length() - 1);
                            }
                            // set the here's ship
                            h[hero].setShip(ship);
                            word = "";
                            // add one to the number of hero's in the game
                            numHeroes = hero + 1;
                            // add one to the number of heros to set up the next hero in array 
                            hero++;
                            // reset count to 0
                            count = 0;
                            break;
                    }
                }
                // all else
                // if there is no comma add the next character to the word
                else {
                    // add char to word
                    word = word + line[i];
                }
            }
        }
    }
}

/*
    - function that reads a text file and gets all the warrior's information
    
    - opens the file and reads the text inside
    - adds a comma to the end of each line to show seperation
    - uses a for loop to read through the string variable and split the words up at each time it runs through a comma
    - takes the string word that it split and enters it as a variable of a warrior in the array 
    - once the for loop runs through the last part of each text line in the string, it will move onto the next hero in the array to enter in that warrior's data
    
    - returns: nothing
    - output: nothing
*/
void gamePlay::getWarriors(string file_name) {
    // declare variables
    int numW = getNumWarriors();
    string name = "";
    int strength = 0;
    int loyalty = 0;
    int morale = 0;
    string freedom = "";
    string ship = "";
    string dragonglass = "";
    int count = 0;
    int warrior = 0;
    
    // create an ouput file stream for writing to file
    ifstream myfile;
    
    // open the file with the file stream
    myfile.open(file_name);
    // declare variables
    string line = "";
    string word = "";
    char comma = ',';
    //char dash = '/';
    
    
    // if statement that checks of text file is open
    if (myfile.is_open()) {
        // while loop that runs through each line of text file
        while (getline(myfile, line)) {
            
            // if statement that checks if the line is empty and to move onto next line
            if (line.empty()) continue;
            
            // add a comma to the end of each line to show different lines from text
            line = line + comma;
            // for loop that runs through each variable in line string
            for (int i = 0; i < line.length(); i++) {
                // if statement that checks if the char in line is equal to a comma
                if (line[i] == comma) {
                    // set block letter
                    switch (count){
                        // case 0 that sets the warrior's name
                        case 0:
                            name = word;
                            // se the warrior's name
                            w[warrior].setWarriorsName(name);
                            word = "";
                            // add one to count to get next case
                            count++;
                            break;
                        // case 1 sets warrior's strength
                        case 1:
                            // if that checks if the word is empty
                            if (!word.empty()) {
                                // convert string to int
                                strength = stoi(word);
                            }
                            // set the warrior's strength
                            w[warrior].setStrength(true, strength);
                            word = "";
                            count++;
                            break;
                        // case 2 sets the warriors loyalty
                        case 2:
                        // if that checks if the word is empty
                            if (!word.empty()) {
                                // convert string to int
                                loyalty = stoi(word);
                            }
                            // set the warrior's loyalty
                            w[warrior].setLoyalty(true, loyalty);
                            word = "";
                            count++;
                            break;
                        // case 3 is to set the warrior's morale
                        case 3:
                            // if that checks if the string is empty
                            if (!word.empty()) {
                                // convert to int
                                morale = stoi(word);
                            }
                            // set the warrior's morale
                            w[warrior].setMorale(true, morale);
                            word = "";
                            count++;
                            break;
                        // case 4 sets the warrior's freedom
                        case 4:
                            freedom = word;
                            w[warrior].setFree(freedom);
                            word = "";
                            count++;
                            break;
                        // case 5 sets if the warrior has a ship or not
                        case 5:
                            ship = word;
                            w[warrior].setShip(word);
                            word = "";
                            count++;
                            break;
                        // case 6 sets if the warrior has dragonglass or not
                        case 6:
                            dragonglass = word;
                            // gets rid of /n at the end of text file read
                            if (warrior < 13) {
                                dragonglass.erase(dragonglass.length() - 1);
                            }
                            w[warrior].setDragonglass(dragonglass);
                            // set word equal to blank string
                            word = "";
                            // add one to the number of total warriors
                            numWarriors = warrior + 1;
                            // add one to warrior count to move to next warrior position in array
                            warrior++;
                            // reset count
                            count = 0;
                            break;
                    }
                }
                // all else
                else {
                    // add char to word
                    word = word + line[i];
                }
            }
        }
    }
}

// get the number of heroes in the game
int gamePlay::getNumHeroes() {
    return numHeroes;
}

// set the number of heroes in the game
void gamePlay::setNumHeroes(int n) {
    numHeroes = n;
}

// return the number of warriors in game
int gamePlay::getNumWarriors() {
    return numWarriors;
}

// set the number of warriors in the game
void gamePlay::setNumWarriors(int num) {
    numWarriors = num;
}

/* function that sets the last position in the hero array to the user's made character/hero
    - take the parameters that were entered in the function and set them to a hero's variables
    - checks the row and column parameters to make sure the user did not input the same row and column as another player
*/
void gamePlay::setUserHero(string name, int m, int f, int a, int r, int c) {
    // declare variables
    int other_r = 0;
    int other_c = 0;
    string amount = "";
    bool t = false;
    
    // for loop that runs through the warriors in the game
    for (int b = 0; b < numWarriors; b++) {
        other_r = w[b].getRow();
        other_c = w[b].getColumn();
        // while loop that checks if the entered row and column match another player
        // if matches, ask the user to re-enter 
        while (r == other_r && c == other_c) {
            cout << "You cannot have the same starting position as another hero/warrior. Please choose another row and column value." << endl;
            cout << "Starting row (1-25): ";
            // user input
            cin >> amount;
            // while loop that tests if the user input it valid
            while (t == false) {
                for (int a = 0; a < amount.length(); a++) {
                    if (isalpha(amount[a]) or amount == "") {
                        cout << "Please enter in a value 1-25: ";
                        // user input
                        cin >> amount;
                        t = false;
                    }
                    else {
                        // convert to int
                        r = stoi(amount);
                        if (r > 25 or r < 1) {
                            cout << "Please enter in a value 1-25: ";
                            // user input
                            cin >> amount;
                            t = false;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }
            }
            t = false;
            // subtract one from the row to account for array placement
            r = r - 1;
            
            // get the user's column input and check if it is integer
            cout << "Starting column (1-16): ";
            // user input
            cin >> amount;
            
            // while loop that tests if the user input it valid
            while (t == false) {
                for (int a = 0; a < amount.length(); a++) {
                    if (isalpha(amount[a]) or amount == "") {
                        cout << "Please enter in a value 1-16: ";
                        // user input
                        cin >> amount;
                        t = false;
                    }
                    else {
                        // convert to string
                        c = stoi(amount);
                        // check if integer is wityhin range
                        if (c > 16 or c < 1) {
                            cout << "Please enter in a value 1-16: ";
                            // user input
                            cin >> amount;
                            t = false;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }    
            }
            t = false;
            // subtract to account for array placement 
            c = c - 1;
        }
    }
    
    // for loop that runs throught the heroes in the game
    for (int a = 0; a < 6; a++) {
        other_r = h[a].getRow();
        other_c = h[a].getColumn();
        
        // while loop that checks if the entered row and column match another player
        // if matches, ask the user to re-enter 
        while (r == other_r && c == other_c) {
            cout << "You cannot have the same starting position as another hero/warrior. Please choose another row and column value." << endl;
            cout << "Starting row (1-25): ";
            cin >> amount;
            
            // while loop that tests if the user input it valid
            while (t == false) {
                 for (int a = 0; a < amount.length(); a++) {
                    if (isalpha(amount[a]) or amount == "") {
                        cout << "Please enter in a value 1-25: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        r = stoi(amount);
                        if (r > 25 or r < 1) {
                            cout << "Please enter in a value 1-25: ";
                            cin >> amount;
                            t = false;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }    
            }
            t = false;
            // subtract from row to account for array placement
            r = r - 1;
            
            cout << "Starting column (1-16): ";
            cin >> amount;
            
            // while loop that tests if the user input it valid
            while (t == false) {
                for (int a = 0; a < amount.length(); a++) {
                    if (isalpha(amount[a]) or amount == "") {
                        cout << "Please enter in a value 1-16: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        c = stoi(amount);
                        if (c > 16 or c < 1) {
                            cout << "Please enter in a value 1-16: ";
                            cin >> amount;
                            t = false;
                        }    
                        else {
                            t = true;
                            break;
                        }
                    }
                }    
            }
            t = false;
            // subtract to account for array placement 
            c = c - 1;
        }
    }
    // set all the varaibles to the user's made hero 
    //h[6] = hero;
    h[6].setHeroName(name);
    //cout << "Name: " << h[6].getHeroName() << endl;
    h[6].setMoney(true, m);
    //cout << "Money: " << h[6].getMoney() << endl;
    h[6].setInfluence(true, f);
    //cout << "Influence: " << h[6].getInfluence() << endl;
    h[6].setArmySize(true, a);
    //cout << "Army: " << h[6].getArmySize() << endl;
    h[6].setRow(r);
    //cout << "Row: " << h[6].getRow() << endl;
    h[6].setColumn(c);
    //cout << "Column: " << h[6].getColumn() << endl;
    if (map[h[6].getRow()][h[6].getColumn()] == "w") {
        h[6].setShip("yes");
        //cout << "Ship: " << h[6].getShip() << endl;
    }
    // add one to the total of heroes in the game
    numHeroes++;
    
}

/* function that reads the text file that holds the map and enters it into an array called map
    - import and stream through a text file
    - get the information in the text file and put it into a string
    - run through the string and cplit the function at every comma
    - enter in the split char into the map array to hold tile type
    - after the map is entered into the array, get the dragonglass map 
        * get a random row and column and set that place to a location with dragonglass
        * do this 5 times
*/
void gamePlay::getMap(string map_file) {
    // import a text file and read the file
    // enter the chars into the array map
    
    // create an ouput file stream for writing to file
    ifstream myfile;
    
    // open the file with the file stream
    myfile.open(map_file);
    // declare variables
    string line = "";
    string block_letter = "";
    char comma = ',';
    char dash = '/';
    int r = 0;
    int c = 0;
    
    
    // if statement that checks of text file is open
    if (myfile.is_open()) {
        // while loop that runs through each line of text file
        while (getline(myfile, line)) {
            
            // if statement that checks if the line is empty and to move onto next line
            if (line.empty()) continue;
            
            // add a comma to the end of each line to show different lines from text
            line = line + dash;
            // for loop that runs through each variable in line string
            for (int i = 0; i < line.length(); i++) {
                // if statement that checks if the char in line is equal to a comma
                if (line[i] == comma) {
                    // set block letter
                    map[r][c] = block_letter;
                    // set word equal to blank string
                    if (c <= 16) {
                        c++;
                        block_letter = "";
                    }
                }
                // else if the line is equal to a dash 
                else if (line[i] == dash) {
                    // if the row is less than 24
                    if (r < 24) {
                        // get rid of the /n from the end of the text file read
                        block_letter.erase(block_letter.length() - 1);
                    }
                    // set block letter
                    map[r][c] = block_letter;
                    // add one to go to next row
                    // if the row is less or equal to 25
                    if (r <= 25) {
                        // add one to row 
                        r++;
                        c = 0;
                        // set word equal to blank string
                        block_letter = "";
                    }
                }
                // all else
                else {
                    // add char to word
                    block_letter = block_letter + line[i];
                }
            }
        }
    }
    
    // place 5 dragonglass in random locations
    int random_r = 0;
    int random_c = 0;
    
    // for loop that gets a random location for dragonglass 5 times
    for (int a = 0; a < 5; a++) {
        // get random row location (1-25)
        random_r = random() % 24 + 1;
        //cout << "Row: " << random_r << endl;
        // get random column location (1-16)
        random_c = random() % 15 + 1;
        // set that place to true for dragonglass
        dp_locations[random_r][random_c] = true;
    }
    
    // TEST
    // for (int a = 0; a < 25; a++) {
    //     cout << '|';
    //     for (int b = 0; b < 16; b++) {
    //         cout << dp_locations[a][b] << '|';
    //     }
    //     cout << endl;
    // }
    
    // cout << endl;
    
    // for (int r = 0; r < 25; r++) {
    //     cout << '|';
    //     for (int c = 0; c < 16; c++) {
    //         cout << map[r][c] << '|';
    //     }
    //     cout << endl;
    // }
}

/* function that reads the city text file and enters the variables and city into array of Cities class
    - opens the file and reads the text inside
    - adds a comma to the end of each line to show seperation
    - uses a for loop to read through the string variable and split the words up at each time it runs through a comma
    - takes the string word that it split and enters it as a variable for certian setter in Cities class for that object in the array 
    - once the for loop runs through the last part of each text line in the string, it will move onto the next city in the array to enter in that city's data
    
    - returns: nothing
    - output: nothing
*/
void gamePlay::getCitiesInfo(string file_name) {
    // decalare variables
    string l = "";
    string name = "";
    int m = 0;
    int a = 0;
    int p = 0;
    int count = 0;
    int city = 0;
    
    // create an ouput file stream for writing to file
    ifstream myfile;
    
    // open the file with the file stream
    myfile.open(file_name);
    // declare variables
    string line = "";
    string word = "";
    char comma = ',';
    //char dash = '/';
    
    
    // if statement that checks of text file is open
    if (myfile.is_open()) {
        // while loop that runs through each line of text file
        while (getline(myfile, line)) {
            
            // if statement that checks if the line is empty and to move onto next line
            if (line.empty()) continue;
            
            // add a comma to the end of each line to show different lines from text
            line = line + comma;
            // for loop that runs through each variable in line string
            for (int i = 0; i < line.length(); i++) {
                // if statement that checks if the char in line is equal to a comma
                if (line[i] == comma) {
                    // set block letter
                    switch (count){
                        // case 0 sets the city's letter
                        case 0:
                            //cout << "City: " << city << endl; 
                            for (int i = 0; i < word.length(); i++) {
                                l = word[i];    
                            }
                            c[city].setLetter(l);
                            //cout << c[city].getLetter() << endl;
                            word = "";
                            count++;
                            break;
                        // case 1 sets the city's name
                        case 1:
                            name = word;
                            c[city].setCityName(name);
                            //cout << c[city].getCityName() << endl;
                            word = "";
                            count++;
                            break;
                        // case 2 is to set the city's money value
                        case 2:
                            if (!word.empty()) {
                                m = stoi(word);
                            }
                            c[city].setCityMoney(m);
                            //cout << c[city].getCityMoney() << endl;
                            word = "";
                            count++;
                            break;
                        // case 3 is to set the city's army value
                        case 3:
                            if (!word.empty()) {
                                a = stoi(word);
                            }
                            c[city].setCityArmy(a);
                            //cout << c[city].getCityArmy() << endl;
                            word = "";
                            count++;
                            break;
                        // case 4 sets the city's points
                        case 4:
                            if (!word.empty()) {
                                p = stoi(word);
                            }
                            c[city].setCityPoints(p);
                            //cout << c[city].getCityPoints() << endl;
                            word = "";
                            count = 0;
                            city++;
                            break;
                    }
                }
                // all else
                // add the char to the string
                else {
                    // add char to word
                    word = word + line[i];
                }
            }
        }
    }
}

/* function that sets the warrior's location to the hero
    - runs through each hero's location 
    - calls the set warriors to hero function
*/
void gamePlay::setWarriorsToHeroLocation() {
    // declare variables
    int place = 0;
    int r = 0;
    int c = 0;
    
    // for loop that gets the location of the hero in game and calls the set warrior to hero function
    // sets the hero's warriors to the hero's location
    for (int i = 0; i < numHeroes; i++) {
        r = h[i].getRow();
        c = h[i].getColumn();
        // call function with row anc column variables
        h[i].setWtoH(r, c);
    }
}


/* function that updates the warriors in the game
    - checks if the warrior is free or not 
    - if the warrior is not free, update the location of the warrior to it's hero
    - if the warrior is free, set them free so they do not get updated to hero again
    
    returns: nothing
    outputs: nothing
*/
void gamePlay::getUpdateWarriors() {
    // declare varaibles
    int num_warriors = 0;
    Warriors update_warrior;
    string name = "";
    int place = -2;
    
    // for loop that runs through the number of warriors in the game
    for (int i = 0; i < numHeroes; i++) {
        // find the number of warrior's that the hero has
        num_warriors = h[i].getNumWarriors();
        // for loop that runs through the hero's warriors
        for (int a = 0; a < num_warriors; a++) {
            // get the warrior from hero at certain position
            update_warrior = h[i].getCertainWarrior(a);
            // fet the name of the warrior
            name = update_warrior.getWarriorsName();
            // for loop that runs through the number of warriors in the game
            for (int b = 0; b < numWarriors; b++) {
                // if that checks if the warrior name matches the warrior in the game array
                if (name == w[b].getWarriorsName()) {
                    // when match, update the warrior variables in the game 
                    w[b] = update_warrior;    
                }
            }
        }
    }
    
    
    // Way to test whether the warriors should be free or not (are they connected to a hero)
    // if they are not connected to a warrior, set them free
    // for loop that runs through the array of warriors
    for (int y = 0; y < numWarriors; y++) {
        // set the warriors name to name
        name = w[y].getWarriorsName();
        // for loop that runs through the heroes in the game
        for (int z = 0; z < numHeroes; z++) {
            // if that checks if the warrior is connected to hero
            if (place == -1) continue;
            // for loop that runs through the heroes warriors
            for (int x = 0; x < h[z].getNumWarriors(); x++) {
                // if that checks if the warrior is connected to hero
                if (place == -1) continue;
                // set the certain warrior attached to hero to Warriors object
                update_warrior = h[z].getCertainWarrior(x);
                // if that checks if the name of the warrior matches the name of the hero's warrior
                if (name == update_warrior.getWarriorsName()) {
                    // set the place to -1 if the warrior is not free
                    place = -1;
                }
                // all else
                else {
                    // set the place to the warriors place in the array to show that warrior needs to be set free
                    place = y;
                }
            }
        }
        // if that checks if the warrior needs to be set free
        if (place != -1) {
            // set the warrior free
            w[place].setFree("yes");
        }
        // reset the place 
        place = -2;
    }
    
    // TEST
    // for (int z = 0; z < numWarriors; z++) {
    //     cout << "Warrior: " << w[z].getWarriorsName() << endl;
    //     cout << "Freedom: " << w[z].getFree() << endl;
    //     cout << "Location: " << "(" << w[z].getRow() << ", " << w[z].getColumn() << ")" << endl;
    //     cout << "DP: " << w[z].getDragonglass() << endl;
    // }
    
}

/* function that sets the location of free warriors in the beginning of game
    - Runs through all the warriors in the game and checks who is free
    - If a warrior is free, check if they have a ship or not
        * if the user has a ship, place them on a water tile 
        * if the user does not have a ship place them on a land tile
    - get the warriors new position with random 

    returns: none
    output: none
*/

void gamePlay::setFreeWarriors() {
    // declare variables
    int other_r = 0;
    int other_c = 0;
    bool right_land = false;
    int r = 0;
    int c = 0;
    string freedom = "";
    bool ship = false;
    
    // for loop that runs throught the number of warriors in the game
    for (int i = 0; i < numWarriors; i++) {
        // set variable to warrior freedom
        freedom = w[i].getFree();
        // set variable to warrior ship
        ship = w[i].getShip();
        // if that checks if the warrior is free and has a ship
        if (freedom == "yes" && ship == 1) {
            // while loop that runs if the random row and column is not a the correct land tile for warrior to start on
            while (right_land == false) {
                // get random ints
                r = random() % 24 + 1;
                c = random() % 15 + 1;
                
                // for loop that gets the number of warriors in the game
                for (int b = 0; b < numHeroes; b++) {
                    other_r = w[b].getRow();
                    other_c = w[b].getColumn();
                    
                    // while loop that checks if the warrior has the same location as another warrior in the game
                    // if they do, get new row and column
                    while (r == other_r && c == other_c) {
                        r = random() % 24 + 1;
                        c = random() % 15 + 1;
                    }
                }
                
                // for loop that runs through the other heroes in the game and gets their position
                for (int a = 0; a < 6; a++) {
                    other_r = h[a].getRow();
                    other_c = h[a].getColumn();
                    
                    // while loop that checks if the warrior has the same location as another warrior or hero in the game
                    // if they do, get new row and column
                    while (r == other_r && c == other_c) {
                        r = random() % 24 + 1;
                        c = random() % 15 + 1;    
                    }
                }
                
                // if that checks if the tile on the map is a water tile
                if (map[r][c] == "w") {
                    // set right land to true
                    right_land = true;
                }
            }
            // cout << "The tile is a " << map[r][c] << endl;
            // if the right land is true, set the warrior to that location
            w[i].setRow(r);
            w[i].setColumn(c);
            // 
            // cout << w[i].getWarriorsName() << " row is " << w[i].getRow() << " and column is " << w[i].getColumn() << endl;
            // reset right land
            right_land = false;
        }
        // else if that checks if the freedom of the warrior is yes and if they do not have a ship
        else if (freedom == "yes" && ship == 0) {
            // while loop that runs if the random row and column is not a the correct land tile for warrior to start on
            while (right_land == false) {
                r = random() % 24 + 1;
                c = random() % 15 + 1;
                
                // for loop that gets the number of warriors in the game
                for (int b = 0; b < numWarriors; b++) {
                    other_r = w[b].getRow();
                    other_c = w[b].getColumn();
                    
                    // while loop that checks if the warrior has the same location as another warrior or hero in the game
                    // if they do, get new row and column
                    while (r == other_r && c == other_c) {
                        r = random() % 24 + 1;
                        c = random() % 15 + 1;
                    }
                }
                
                // for loop that runs through the other heroes in the game and gets their position
                for (int a = 0; a < 6; a++) {
                    other_r = h[a].getRow();
                    other_c = h[a].getColumn();
                    
                    // while loop that checks if the warrior has the same location as another warrior or hero in the game
                    // if they do, get new row and column
                    while (r == other_r && c == other_c) {
                        r = random() % 24 + 1;
                        c = random() % 15 + 1;    
                    }
                }
                
                // if that checks if the tile on the map is land
                if (map[r][c] == "p") {
                    right_land = true;
                }
            }
            // set the warrior's location to the location
            w[i].setRow(r);
            w[i].setColumn(c);
            // reset right land
            right_land = false;
        }
    }
}

/* function that gets the points from a location on the map
    - run through all the heroes in the game
    - if the hero already has control of that land move onto the next hero
    - if the hero does not have control of that land, give them control
        * before: check if other hero is on that tile and cannot get control
        * before: check if another hero has control of thay land and remove their control and points from that tile
    - If it is the beginning of the game, set that location to adventured as well so they cannot get resources later
    
    return: none
    output: none
*/

void gamePlay::getLocationPoints() {
    // find the location that the hero is at and determine which tile that is
    // give the player the resources that come from that tile
    int r = 0;
    int clm = 0;
    string tile_type = "";
    int points = 0;
    int place = 0;
    
    // for loop that runs through the heroes in the game
    for (int i = 0; i < numHeroes; i++) {
        // if the hero has no name, continue on 
        if (h[i].getHeroName() == "") continue;
        
        // get hero's location
        r = h[i].getRow();
        clm = h[i].getColumn();
        //
    
        // set the location as adventured 
        
        //check if the user already has control of the land 
        // if they do, continue onto the next hero
        if (h[i].getControl(r, clm) == true) {
            //cout << "CONTROLLED" << endl;
            //cout << h[i].getHeroName() << " points are " << h[i].getPoints() << endl;
            continue;
        }
        // all else
        else {
            // run through all the other heros owned locations
            for (int a = 0; a < numHeroes; a++) {
                // don't compare to the user (can't take away land from self)
                if (a == i) continue;
                // check if hero is on that location, if they are, can't take away location
                if (h[a].getRow() == r && h[a].getColumn() == clm) {
                    break;
                }
                // if that checks if other hero has control of that tile and remove their control from it 
                if (h[a].getControl(r, clm) == true) {
                    //cout << h[a].getHeroName() << "lost control of " << "(" << r << ", " << clm << ")" << endl;
                    // remove control for hero
                    h[a].setControl(false, r, clm);
                    
                    // remove the points from losing control of that tile
                    // if the map tile is land
                    if (map[r][clm] == "p") { 
                        // remove points from land tile
                        h[a].setPoints(false, 2);
                    }
                    // else if water tile
                    else if (map[r][clm] == "w") {
                        // remove points from water tile loss
                        h[a].setPoints(false, 1);
                    }
                    // all else
                    else {
                        // run through each city letter in Cities class to find what city they are on
                        for (int a = 0; a < 26; a++) {
                            // if that checks if the tile type is a City letter
                            if (tile_type == c[a].getLetter()) {
                                // keep the  place in the City c array that is the tile type
                                place = a;
                                // break the loop because tile was found
                                break;
                            }
                        }
                        // set the points equal to the City points value from Cities class
                        points = c[place].getCityPoints();
                        // add the points to the hero to represent that they have control of that tile
                        h[i].setPoints(false, points);    
                    }
                }
            }
            
            // if that checks if turns is 0
            if (turns == 0) {
                h[i].setAdventured(r, clm);
            }
            // give the Hero control of that tile
            h[i].setControl(false, r, clm);
            // set tile type to the tile in the map at location
            tile_type = map[r][clm];
            // if that checks if the tile is a water tile
            if (tile_type == "w") {
                // set point equal to 1 for water tile control point
                points = 1;
                // add that point to hero representing they control that tile
                h[i].setPoints(true, points);
            }
            //else if that checks if the tile is a land tile
            else if (tile_type == "p") {
                // set point equal to 2 for land tile control point
                points = 2;
                // add the points to hero representing they control that tile
                h[i].setPoints(true, points);
            }
            // all else (City tiles)
            else {
                // run through each city letter in Cities class to find what city they are on
                for (int a = 0; a < 26; a++) {
                    // if that checks if the tile type is a City letter
                    if (tile_type == c[a].getLetter()) {
                        // keep the  place in the City c array that is the tile type
                        place = a;
                        // break the loop because tile was found
                        break;
                    }
                }
                // set the points equal to the City points value from Cities class
                points = c[place].getCityPoints();
                // add the points to the hero to represent that they have control of that tile
                h[i].setPoints(true, points);
                
            }
        }
        //cout << h[i].getHeroName() << " points are " << h[i].getPoints() << endl;
    }
}

/* function that gets the mini map for the user to see their location each turn
    - gets the hero's location
    - subtracts 3 from the row and column to start printing from the first tile on mini map
    - Run through a for loop that outputs a tile one at a time
        * if the tile is at the edge of the map show []
        * if the tile is where the player is at show <>
        * if the player is at the edge show [<>]

    return: none
    output: 7x7 mini map
*/

void gamePlay::getMiniMap(int hero) {
    // declare variables
    int count = 0;
    int r = 0;
    int c = 0;
    // represents the maximum number of rows for 7x7
    int max_r = 0;
    
    // TEST 
    // cout << "Hero num: " << hero << endl;
    // cout << "Row: " << h[hero].getRow() << endl;
    // cout << "Column: " << h[hero].getColumn() << endl;
    
    // if statement that gets the warriors row subtracts 3 to get starting value for row mini map
    if (h[hero].getRow() >= 3) {
        r = h[hero].getRow() - 3;
    }
    // condition so the row value is not a negative
    else {
        r = 0;    
    }
    
    // if statement that gets the warrior column and subtracts 3 to get starting value for column mini map
    if (h[hero].getColumn() >= 3) {
        c = h[hero].getColumn() - 3;     
    }
    // condition so the row value is not a negative
    else {
        c = 0;
    }
    
    // find the maximum row value for 7x7 by using row updated row
    if (r == 0) {
        max_r = 4;    
    }
    else {
        max_r = r + 7;
    }
    // if that checks that the row is not greater than 25 (outside value of map array)
    if (max_r > 25) {
        max_r = 25;
    }
    
    // TEST 
    // cout << "New Row and Column: (" << r << ", " << c << ")" << endl;
    
    cout << "Note:" << endl;
    cout << "- water tiles are represented by '~'" << endl;
    cout << "- land tiles are represented by '*'" << endl;
    cout << "- edge of the map is represented by [tile type]" << endl;
    cout << "- you are represented by <tile type>" << endl;
    cout << endl;
    cout << "============ MAP ============" << endl;
    cout << "|";
    
    
    // for loop that prints out 7x7 mini map
    for (int i = 0; i < 49; i++) {
        // condition to check if the column is 16 and if the row is at max
        if ((c + count) == 16 && r != max_r) {
            // reset count 
            count = 0;
            // go to next row
            r++;
            cout << endl;
            // add a | after each tile
            if (r < max_r) {
                 cout << "|";    
            }
        }
        // else if the row is at max, stop printing out
        else if (r == max_r) {
            break;
        }
        // else if that checks if the row or column is an edge piece
        else if (r == 0 || r == 24 || c + count == 0 || c + count == 15) {
            // if that checks if the edge piece is a water tile
            if (map[r][c + count] == "w") {
                // if that checks if the hero has that same column and row
                if (h[hero].getRow() == r && h[hero].getColumn() == c + count) {
                    // display showing edge and hero is there
                    cout << "[<~>]" << "|";    
                }
                // all else
                else {
                    // just edge piece 
                    cout << "[~]" << "|";
                }
            }
            // else if that checks if the tile is a land tile
            else if (map[r][c + count] == "p") {
                // if that checks if the hero is on that same row and column
                if (h[hero].getRow() == r && h[hero].getColumn() == c + count) {
                    // display showing edge and hero is there
                    cout << "[<*>]" << "|";    
                }
                // all else
                else {
                    // just edge
                    cout << "[*]" << "|";
                }
            }
            // all else
            // city tiles
            else {
                // if that checks if the hero is on that same row and column
                if (h[hero].getRow() == r && h[hero].getColumn() == c + count) {
                    // display showing edge and hero is there
                    cout << "[<" << map[r][c + count] << ">]" << "|";    
                }
                // all else
                else {
                    // just edge
                    cout << "[" << map[r][c + count] << "]" << "|"; 
                }
            }
            
            // if that checks if the column is at the edge
            if ((c + count) == 16) {
                // reset count
                count = 0;
            }
            // else if that checks if the row is less than or equal to 24 and count is 6
            else if (count == 6 && r <= 24) {
                // output endline
                cout << endl;
                // reset count
                count = 0;
                // go to next row
                r++;
                // if the row is less than max row
                if (r < max_r) {
                    // put a | after row
                    cout << "|";    
                }
            }
            // else if row is less than or equal to 24 and count is less than 6
            else if (r <= 24 && count < 6) {
                // add one to count
                count++;
            }
        }
        // if that checks if the hero is on that same row and column
        else if (h[hero].getRow() == r && h[hero].getColumn() == c + count) {
            // if that checks if the tile is a water tile
            if (map[r][c + count] == "w") {
                // display showing hero is there and water tile
                cout << "<~>" << "|";
            }
            // else if that checks if the tile is land
            else if (map[r][c + count] == "p") {
                // display showing hero is there and land tile
                cout << "<*>" << "|";
            }
            // all else
            else {
                // display that hero is there and city tile
                cout << "<" << map[r][c + count] << ">" << "|";    
            }
            
            // if the count is equal to 16 (edge of map)
            if ((c + count) == 16) {
                // reset count
                count = 0;
            }
            // all else that checks if count is 6 and if row is less than max
            else if (count == 6 && r < max_r) {
                // output endline
                cout << endl;
                // reset count
                count = 0;
                // go to next row
                r++;
                // if the row is less than the max row
                if (r < max_r) {
                    // add | to show tile
                    cout << "|";    
                }
            }
            // else if that checks if the row is less than max and count is less than 6
            else if (r < max_r && count < 6) {
                // add one to count
                count++;
            }
        }
        // all else
        else {
            // if the tile is a water tile
            if (map[r][c + count] == "w") {
                // show water tile 
                cout << " ~ " << "|";
            }
            // else if map is a land tile
            else if (map[r][c + count] == "p") {
                // show land tile
                cout << " * " << "|";
            }
            // all else
            else {
                // show city tile
                cout << " " << map[r][c + count] << " " << "|";    
            }
            
            // if the count is equal to 16 (edge of map)
            if ((c + count) == 16) {
                // reset count
                count = 0;
            }
            // all else that checks if count is 6 and if row is less than max
            else if (count == 6 && r < max_r) {
                // output endline
                cout << endl;
                // reset count
                count = 0;
                // go to next row
                r++;
                // if the row is less than the max row
                if (r < max_r) {
                    // add | to show tile
                    cout << "|";    
                }
            }
            // else if that checks if the row is less than max and count is less than 6
            else if (r < max_r && count < 6) {
                // add one to count
                count++;
            }
        }
        //cout << "(" << r << ", " << c + count << ")" << endl;
    }
    cout << "=============================" << endl;
    cout << endl;
}

/* function that checks if there is a free warrior near by and adds that warrior to the hero near 
    - for loop that runs through all the heroes in the game
    - gets the hero's location and changes the row and column to search through a 5x5 
    - for loop that runs through all the locations in the 5x5 and checks if there are any other heroes around
        * if there are no other heroes in the area continue on to see if other warriors are in the are
        * if there are other heroes in the location, then no one gets a warrior in that location
    - for loop that runs through all the locations in the 5x5 and checks if a warrior has that same location
        * if there is a warrior in the area, give the warriot to the hero only if they have room for another
        
    return: nothing
    outputs: nothing
*/

void gamePlay::getCheckNearWarriors(int hero) {
    // declare variables
    int count = 0;
    int place = 0;
    int r = 0;
    int c = 0;
    // represents the maximum number of rows for 5x5
    int max_r = 0;
    int max_c = 0;
    int hero_count = 0;
    int warrior_count = 0;
    
    // for loop that runs through all the heroes in the game
    for (int i = 0; i < numHeroes; i++) {
        // TEST
        //cout << h[i].getHeroName() << endl;
        // cout << "Hero num: " << i << endl;
        // cout << "Row: " << h[i].getRow() << endl;
        // cout << "Column: " << h[i].getColumn() << endl;
        //
        
        // if statement that checks if the user has less than 4 warriors
        if (h[i].getNumWarriors() < 4) {
        
            //if statement that gets the warriors row subtracts 3 to get starting value for row mini map
            if (h[i].getRow() >= 2) {
                r = h[i].getRow() - 2;
            }
            // condition so the row value is not a negative
            else {
                r = 0;
            }
            
            // if statement that gets the warrior column and subtracts 3 to get starting value for column mini map
            if (h[i].getColumn() >= 2) {
                c = h[i].getColumn() - 2;     
            }
            // condition so the row value is not a negative
            else {
                c = 0;
            }
            
            // find the maximum row value for 7x7 by using row updated row
            if (r == 0) {
                max_r = 3;
            }
            // all else
            else {
                max_r = r + 5;
            }
            
            max_c = c + 5;
            // if that checks that the row is not greater than 25 (outside value of map array)
            if (max_r > 25) {
                max_r = 25;
            }
            
            // for loop that checks if another hero is proximity to the hero user
            // nested for loop that runs through the 5x5 proximity map
            for (int a = r ; a < max_r; a++) {
                for (int b = c; b < max_c; b++) {
                    // display the row and column
                    // cout << "(" << a << ", " << b << ")" << endl;
                    // for loop that runs through each hero
                    for (int z = 0; z < numHeroes; z++) {
                        // if statement that doesn't allow the user location to be compared to self
                        if (z == i) continue;
                        // if that checks if the row and column in the proximity map is equal to another hero's location
                        if (h[z].getRow() == a && h[z].getColumn() == b) {
                            // set place to location of hero in array to have a battle with
                            place = z;
                            // add one to the count (represents the amount of heroes in proximity)
                            hero_count++;
                            // output the hero that has same place in proximity
                            //cout << h[z].getHeroName() << " has same place" << endl;    
                        }
                    }
                }
                // cout << endl;
            }
            
            // if that checks if the hero_count is 0 (no other heroes in that area)
            if (hero_count == 0) {
                place = 0;
                // for loop that checks if another warrior is proximity to the hero user
                // nested for loop that runs through the 5x5 proximity map
                for (int a = r ; a < max_r; a++) {
                    for (int b = c; b < max_c; b++) {
                        // display the row and column
                        // cout << "(" << a << ", " << b << ")" << endl;
                        // for loop that runs through each warrior
                        for (int z = 0; z < numWarriors; z++) {
                            // if statement that doesn't allow the user location to be compared to self
                            if (z == i or w[z].getFree() == "no") continue;
                            // if that checks if the row and column in the proximity map is equal to another warrior's location
                            if (w[z].getRow() == a && w[z].getColumn() == b) {
                                // set place to location of warrior in array to have get warrior
                                place = z;
                                // if the user has less than 4 warriors, set the near warrior to them
                                if (h[i].getNumWarriors() < 4) {
                                    // set the warrior to the ies warrior array
                                    h[i].setWarriors(w[place]);
                                    // set the warriors freedom to no
                                    w[place].setFree("no");
                                    // if that checks if the warrior's loyalty and morale is less than 100
                                    if (w[place].getLoyalty() < 100 && w[place].getMorale() < 100) {
                                        w[place].setLoyalty(true, 10);
                                        w[place].setMorale(true, 10);
                                    }
                                    
                                    // TEST
                                    // display messages
                                    // h[i].getNamesofWarriors();
                                    // cout << endl;
                                    //cout << "Is captured warrior free: " << w[place].getFree() << endl; 
                                    //
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/* function that gets the user's surroundings for other heroes
    - gets the user's location and changes the row and column to search through a 5x5 
    - for loop that runs through all the locations in the 5x5 and checks if there are any other heroes around
        * if there are no other heroes in the area continue game
    - if there are other heroes, then ask the user what they want to do
        - Speech
        - Travel
        - Battle
    - allow the user to enter in their choice and call the other function based on their choice
    - the function call will return the user with updated variables to be updated to game
    - then call the winner function from battle class to determine if the hero won or lost that choice
        * if the user lost the speech or buy out function, tell they lost and have escaped and give them a new location on the map
        * if the user lost the battle, call the get continue game function with false to end the game 
        * if the user won, then the other hero retires 
            * remove hero from the hero array in class
        * continue game

    return: Hero object 
    output: none
*/

void gamePlay::getSurroundings(int hero) {
    // check if a hero is within their proximity (2 tiles in any direction) (5x5)
    // done by running through each hero's position and checking if their row and column
    // are in that proximity
    // if hero is within direction, call the Battle class to start battle
    
    // declare variables
    Heroes hero_return;
    bool battle = false;
    int count = 0;
    int place = 0;
    int r = 0;
    int c = 0;
    // represents the maximum number of rows for 5x5
    int max_r = 0;
    int max_c = 0;
    string option = "";
    int choice_num = 0;
    bool t = false;
    
    // TEST
    // display variables
    // cout << "Hero num: " << hero << endl;
    // cout << "Row: " << h[hero].getRow() << endl;
    // cout << "Column: " << h[hero].getColumn() << endl;
    // 
    
    //if statement that gets the warriors row subtracts 3 to get starting value for row mini map
    if (h[hero].getRow() >= 2) {
        r = h[hero].getRow() - 2;
    }
    // condition so the row value is not a negative
    else {
        r = 0;
    }
    
    // if statement that gets the warrior column and subtracts 3 to get starting value for column mini map
    if (h[hero].getColumn() >= 2) {
        c = h[hero].getColumn() - 2;     
    }
    // condition so the row value is not a negative
    else {
        c = 0;
    }
    
    // find the maximum row value for 7x7 by using row updated row
    if (r == 0) {
        max_r = 3;
    }
    // else if (r == 1) {
    //     max_r = 5;
    // }
    else {
        max_r = r + 5;
    }
    
    max_c = c + 5;
    // if that checks that the row is not greater than 25 (outside value of map array)
    if (max_r > 25) {
        max_r = 25;
    }
    
    // for loop that checks if another hero is proximity to the hero user
    // nested for loop that runs through the 5x5 proximity map
    for (int a = r ; a < max_r; a++) {
        for (int b = c; b < max_c; b++) {
            // display the row and column
            //cout << "(" << a << ", " << b << ")" << endl;
            // for loop that runs through each hero
            for (int z = 0; z < numHeroes; z++) {
                // if statement that doesn't allow the user location to be compared to self
                if (z == hero) continue;
                // if that checks if the row and column in the proximity map is equal to another hero's location
                if (h[z].getRow() == a && h[z].getColumn() == b) {
                    // set place to location of hero in array to have a battle with
                    place = z;
                    // add one to the count (represents the amount of heroes in proximity)
                    count++;
                    // output the hero that has same place in proximity
                    //cout << h[z].getHeroName() << " has same place" << endl;    
                }
            }
        }
        //cout << endl;
    }
    
    // display the users options and ask them what they want to do for the battle
    // if there is only one user in the user's proximity map, then start a battle with that user
    if (count == 1) {
        // set the user and the opponent into the Battle class as objects of Heroes
        
        //cout << endl;
        // output the options that the user has when other hero is in proximty
        // MENU
        //cout << h[hero].getHeroName() << endl;
        //h[hero].getNamesofWarriors();
        //cout << endl;
    
        cout << h[place].getHeroName() << " is near. What will you do?" << endl;
        //1h[place].getNamesofWarriors();
        cout << "0. Give a speech: use your influence" << endl;
        cout << "1. Buy them outright: use your money" << endl;
        cout << "2. Battle: use the strength of your warriors and the size of your army" << endl;
        cin >> option;
        
        // for loop that checks if the user has inputed a letter
        while (t == false) {
            for (int a = 0; a < option.length(); a++) {
                // while that loops as long as the user inputs a letter
                if (isalpha(option[a]) or option == "") {
                    // ask the user to enter valid number
                    cout << "Please enter in a value 0-2: ";
                    cin >> option;
                    t = false;
                }
                else {
                    // conver the string to integers
                    choice_num = stoi(option);
                    // while loop that runs if the number values are not vaild in this case
                    if (choice_num > 2 or choice_num < 0) {
                        // ask user to re-enter values
                        cout << "Please enter in a value 0-2: ";
                        cin >> option;
                        t = false;
                    }
                    else {
                        t = true;
                        break;
                    }
                }
            }    
        }
        t = false;
        //
        
        // if the user selected to battle
        if (choice_num == 2) {
            // declare variables
            int num_user_warriors = h[hero].getNumWarriors();
            int num_opp_warriors = h[place].getNumWarriors();
            
            // if that checks if the both users have same amount of warriors
            if (num_user_warriors == 0 && num_opp_warriors == 0) {
                // declare varibales
                int user_army = h[hero].getArmySize();
                int opp_army = h[place].getArmySize();
                
                // output message
                // cout << "OG User army size: " << user_army << endl;
                // cout << "OG Opponent army size: " << opp_army << endl;
                
                // if statement that checks if the user and the opponent has the same army size
                if (user_army == opp_army) {
                    // cout message
                    cout << "It is a tie. You both lose half your army." << endl;
                    
                    // if statement that checks if the army size for the user is odd
                    if (user_army % 2 != 0) {
                        // subtract one from the army size
                        user_army--;
                    }
                    // if that checks if the army size for the opponent is odd
                    else if (opp_army % 2 != 0) {
                        // subtract one from the opponents army
                        opp_army--;
                    }
                    
                    // display messages
                    // cout << "OG User army size: " << h[hero].getArmySize() << endl;
                    // cout << "OG Opponent army size: " << h[place].getArmySize() << endl;
                    
                    // set the army size for the user to half 
                    h[hero].setArmySize(false, user_army/2);
                    // set the army sise of the opponent to half
                    h[place].setArmySize(false, opp_army/2);
                    
                    // display message
                    // cout << "User army size: " << h[hero].getArmySize() << endl;
                    // cout << "Opponent army size: " << h[place].getArmySize() << endl;
                    // set continue game to true because game isn't over
                    setContinueGame(true);
                }
                // if the army sizes aren't the same
                else {
                    // cout << "BATLLE" << endl;
                    // cout << "Choice 1" << endl;
                    // call the getBattlePlay function in Battle class using user and opponent 
                    hero_return = b.getBattlePlay(h[hero], h[place], true);
                    // set the returned user from the function to itself to update variables from Battle class
                    h[hero] = hero_return;
                    // call getWinner function in Battle class to see if the user won
                    battle = b.getWinner();
                    // call the continue game function with the battle return to determine if the game needs to end or not
                    setContinueGame(battle);
                }
            }
            // else call battle
            else {
                // cout << "BATLLE" << endl;
                // cout << "Choice 2" << endl;
                // call the getBattlePlay function in Battle class using user and opponent 
                hero_return = b.getBattlePlay(h[hero], h[place], true);
                // set the returned user from the function to itself to update variables from Battle class
                h[hero] = hero_return;
                // call getWinner function in Battle class to see if the user won
                battle = b.getWinner();
                // call the continue game function with the battle return to determine if the game needs to end or not
                setContinueGame(battle);
            }
        }
        else {
            // if statement that checks if the users choice is to give speech
            if (choice_num == 0) {
                // call the getSpeech function in Battle class using user and opponent 
                hero_return = b.getSpeech(h[hero], h[place]);
                // set the returned user from the function to itself to update variables from Battle class
                h[hero] = hero_return;
                // call the continue game function with the battle return to determine if the game needs to end or not
                battle = b.getWinner();
                
            }
            // else if that checks if the users choice is to buyout
            else if (choice_num == 1) {
                // call the getBuyOut function in Battle class using user and opponent
                hero_return = b.getBuyOut(h[hero], h[place]);
                // set the returned user from the function to itself to update variables from Battle class
                h[hero] = hero_return;
                // call the continue game function with the battle return to determine if the game needs to end or not
                battle = b.getWinner();
            }
        }
        
        // get the number of heroes left in game
        int num_h = getNumHeroes();
        //cout << endl; 
        // if the user won the battle
        if (battle == true) {
            // subtract a hero from the game to represent a hero's loss
            setNumHeroes(num_h - 1);
            // set num_h to the new number of heroes left
            num_h = getNumHeroes();
            
            // output messages
            // cout << "AFTER BATTLE" << endl;
            // cout << "# of heroes: " << num_h << endl;
            
            // for loops that run through the users controlled land 
            for (int r = 0; r < 26; r++) {
                for (int c = 0; c < 16; c++) {
                    // checks to see if the opponent that lost has control of what land
                    if (h[place].getControl(r, c) == true) {
                        // set the opponents controlled land to the users controlled land
                        h[hero].setControl(false, r, c);
                        h[hero].getAdventured(r, c);
                    }
                }
            }
            // at the end of the battle, move the heroes in the hero array to account for retired hero from battle
            for (int d = place; d < num_h; d++) {
                h[d] = h[d+1];
            }
            
            // output the names of the heroes left and their location
            //cout << "Names: " << endl;
            for (int i = 0; i < num_h; i++) {
                if (h[i].getHeroName() == "") continue;
                // cout << h[i].getHeroName() << endl;
                // cout << "(" << h[i].getRow() << ", " << h[i].getColumn() << ")" << endl;
            }
            
            // TEST
            // get the controlled map for the user
            // cout << endl;
            // cout << "CONTROL MAP" << endl;
            // h[hero].getControlMap();
            //
        }
        // if the user loses
        else {
            // declare variables
            bool right_land = false;
            bool ship = h[hero].getShip();
            int other_c = 0;
            int other_r = 0;
            
            // if statement that checks if the user has a ship
            if (ship == true) {
                // get a random location for the users row and column
                r = random() % 24 + 1;
                c = random() % 15 + 1;
                
                // for loop that runs through each warrior in array
                for (int b = 0; b < numWarriors; b++) {
                    // sets the warriors column and row to variables
                    other_r = w[b].getRow();
                    other_c = w[b].getColumn();
                    
                    // while loop that runs as long as the random location matches another warriors location
                    // this allows for the user to not have the same location as another warrior
                    while (r == other_r && c == other_c) {
                        // get a new random row and column
                        r = random() % 24 + 1;
                        c = random() % 15 + 1;
                    }
                }
                
                // for loop that runs through each hero in array
                for (int a = 0; a < 6; a++) {
                    // sets the hero's row and column to variables
                    other_r = h[a].getRow();
                    other_c = h[a].getColumn();
                    
                    // while loop that runs as long as the random location matches another warriors location
                    // this allows for the user to not have the same location as another warrior
                    while (r == other_r && c == other_c) {
                        // get a new random row and column
                        r = random() % 24 + 1;
                        c = random() % 15 + 1;    
                    }
                }
            }
            // all else
            // for user that doesn't have a ship
            else {
                // while loop that runs as long as the right land (land tile) is not true
                while (right_land == false) {
                    // get a random location for the row and column
                    r = random() % 8 + 1;
                    c = random() % 15 + 1;
                    
                    // for loop that runs through each warrior in array
                    for (int b = 0; b < numWarriors; b++) {
                        // sets the warriors column and row to variables
                        other_r = w[b].getRow();
                        other_c = w[b].getColumn();
                        
                        // while loop that runs as long as the random location matches another warriors location
                        // this allows for the user to not have the same location as another
                        while (r == other_r && c == other_c) {
                            // get a new random row and column
                            r = random() % 8 + 1;
                            c = random() % 15 + 1;
                        }
                    }
                    
                    // for loop that runs through each hero in array
                    for (int a = 0; a < 6; a++) {
                        // sets the hero's row and column to variables
                        other_r = h[a].getRow();
                        other_c = h[a].getColumn();
                        
                        // while loop that runs as long as the random location matches another warriors location
                        // this allows for the user to not have the same location as another 
                        while (r == other_r && c == other_c) {
                            // get a new random row and column
                            r = random() % 8 + 1;
                            c = random() % 15 + 1;    
                        }
                    }
                    
                    // if statement that checks if the new location is a land tile
                    if (map[r][c] == "p") {
                        // if true, set the right_land to true
                        right_land = true;
                    }    
                }
                // set the user's new location
                h[hero].setRow(r);
                h[hero].setColumn(c);
                // display message
                // cout << "The tile is a " << map[r][c] << endl; 
                // cout << h[hero].getHeroName() << " row is " << h[hero].getRow() << " and column is " << h[hero].getColumn() << endl;
            }
        }
    }
}

/* function that checks the surroundings of the other heroes and if they need to battle
    - gets the hero's location and changes the row and column to search through a 5x5 
    - for loop that runs through all the locations in the 5x5 and checks if there are any other heroes around
        * if there are no other heroes in the area continue game
    - if there are other heroes, then have the two heroes battle
    - the function call will return the winning hero with updated variables to be updated to game
        * the other hero retires 
            * remove hero from the hero array in class
        * continue game

    return: Hero object
    output: none
*/

void gamePlay::getCheckOthersSurroundings(int hero) {
    
    //cout << "HERO NUMBER: " << hero << endl;
    
    // declare variables
    Heroes hero_return;
    bool battle = false;
    int count = 0;
    int place = 0;
    int r = 0;
    int c = 0;
    // represents the maximum number of rows for 5x5
    int max_r = 0;
    int max_c = 0;
    
    for (int i = 0; i < numHeroes; i++) {
        if (h[i].getHeroName() == "" or i == hero) continue;
        
        // TEST 
        //cout << h[i].getHeroName() << endl;
        // display variables
        // cout << "Hero num: " << i << endl;
        // cout << "Row: " << h[i].getRow() << endl;
        // cout << "Column: " << h[i].getColumn() << endl;
        //
        
        //if statement that gets the warriors row subtracts 3 to get starting value for row mini map
        if (h[i].getRow() >= 2) {
            r = h[i].getRow() - 2;
        }
        // condition so the row value is not a negative
        else {
            r = 0;
        }
        
        // if statement that gets the warrior column and subtracts 3 to get starting value for column mini map
        if (h[i].getColumn() >= 2) {
            c = h[i].getColumn() - 2;     
        }
        // condition so the row value is not a negative
        else {
            c = 0;
        }
        
        // find the maximum row value for 7x7 by using row updated row
        if (r == 0) {
            max_r = 3;
        }
        else {
            max_r = r + 5;
        }
        
        max_c = c + 5;
        // if that checks that the row is not greater than 25 (outside value of map array)
        if (max_r > 25) {
            max_r = 25;
        }
        
        // for loop that checks if another hero is proximity to the hero user
        // nested for loop that runs through the 5x5 proximity map
        for (int a = r ; a < max_r; a++) {
            for (int b = c; b < max_c; b++) {
                // display the row and column
                //cout << "(" << a << ", " << b << ")" << endl;
                // for loop that runs through each hero
                for (int z = 0; z < numHeroes; z++) {
                    // if statement that doesn't allow the user location to be compared to self
                    if (z == i or z == hero or h[z].getHeroName() == "") continue;
                    // if that checks if the row and column in the proximity map is equal to another hero's location
                    if (h[z].getRow() == a && h[z].getColumn() == b) {
                        // set place to location of hero in array to have a battle with
                        place = z;
                        // add one to the count (represents the amount of heroes in proximity)
                        count++;
                        // output the hero that has same place in proximity
                        //cout << h[z].getHeroName() << " has same place" << endl;    
                    }
                }
            }
            //cout << endl;
        }
        
        // for testing purpose to check if control is getting updated
        // cout << endl;
        // cout << "CONTROL MAP" << endl;
        // h[i].getControlMap();
    //
    
        if (count == 1) {
            // set the user and the opponent into the Battle class as objects of Heroes
            // declare variables
            int num_user_warriors = h[i].getNumWarriors();
            int num_opp_warriors = h[place].getNumWarriors();
            
            // if that checks if the both users have same amount of warriors
            if (num_user_warriors == 0 && num_opp_warriors == 0) {
                // declare varibales
                int user_army = h[i].getArmySize();
                int opp_army = h[place].getArmySize();
                
                // TEST
                // output message
                // cout << "OG User army size: " << user_army << endl;
                // cout << "OG Opponent army size: " << opp_army << endl;
                
                // if statement that checks if the user and the opponent has the same army size
                if (user_army == opp_army) {
                    // cout message
                    cout << "It is a tie. You both lose half your army." << endl;
                    
                    // if statement that checks if the army size for the user is odd
                    if (user_army % 2 != 0) {
                        // subtract one from the army size
                        user_army--;
                    }
                    // if that checks if the army size for the opponent is odd
                    else if (opp_army % 2 != 0) {
                        // subtract one from the opponents army
                        opp_army--;
                    }
                    
                    // TEST
                    // display messages
                    // cout << "OG User army size: " << h[i].getArmySize() << endl;
                    // cout << "OG Opponent army size: " << h[place].getArmySize() << endl;
                    
                    // set the army size for the user to half 
                    h[i].setArmySize(false, user_army/2);
                    // set the army sise of the opponent to half
                    h[place].setArmySize(false, opp_army/2);
                    
                    // TEST
                    // display message
                    // cout << "User army size: " << h[i].getArmySize() << endl;
                    // cout << "Opponent army size: " << h[place].getArmySize() << endl;
                }
                // if the army sizes aren't the same
                else {
                    // cout << "BATLLE" << endl;
                    // cout << "Choice 1" << endl;
                    // call the getBattlePlay function in Battle class using user and opponent 
                    hero_return = b.getBattlePlay(h[i], h[place], false);
                    // set the returned user from the function to itself to update variables from Battle class
                    h[i] = hero_return;
                    // call getWinner function in Battle class to see if the user won
                    battle = b.getWinner();
                }
            }
            // else call battle
            else {
                // cout << "BATLLE" << endl;
                // cout << "Choice 2" << endl;
                // call the getBattlePlay function in Battle class using user and opponent 
                hero_return = b.getBattlePlay(h[i], h[place], false);
                // set the returned user from the function to itself to update variables from Battle class
                h[i] = hero_return;
                // call getWinner function in Battle class to see if the user won
                 battle = b.getWinner();
            }
            
            // get the number of heroes left in game
            int num_h = getNumHeroes();
            //cout << endl; 
            // if the user won the battle
            if (battle == true) {
                // subtract a hero from the game to represent a hero's loss
                setNumHeroes(num_h - 1);
                // set num_h to the new number of heroes left
                num_h = getNumHeroes();
                
                // output messages
                // cout << "AFTER BATTLE" << endl;
                // cout << "# of heroes: " << num_h << endl;
                
                // for loops that run through the users controlled land 
                for (int r = 0; r < 26; r++) {
                    for (int c = 0; c < 16; c++) {
                        // checks to see if the opponent that lost has control of what land
                        if (h[place].getControl(r, c) == true) {
                            // set the opponents controlled land to the users controlled land
                            h[i].setControl(false, r, c);
                            h[i].getAdventured(r, c);
                        }
                    }
                }
                // at the end of the battle, move the heroes in the hero array to account for retired hero from battle
                for (int d = place; d < num_h; d++) {
                    h[d] = h[d+1];
                }
                
                
                // TEST
                // output the names of the heroes left and their location
                // cout << "Names: " << endl;
                // for (int i = 0; i < num_h; i++) {
                //     if (h[i].getHeroName() == "") continue;
                //     cout << h[i].getHeroName() << endl;
                //     cout << "(" << h[i].getRow() << ", " << h[i].getColumn() << ")" << endl;
                // }
                
                // get the controlled map for the user
                // cout << endl;
                // cout << "CONTROL MAP" << endl;
                // h[i].getControlMap();
            }
            // reset count
            count = 0;
        }
    }
}


/* function that gets the location resources when they travel on a non adventured area
    - for loop that runs through all the heroes in the game
    - get the heroes row and column
    - call the get adventured function with their location to check if the location was already traveled to
        * if the hero already has adeventured that location continue the game
        * if the user has not traveled that location, give them the resources associated with that location
        * if the location tile is a city that they have not traveled to ask them if they want to hear
         rumors and if they want more soldiers
         
    return: none
    output: messages
*/

void gamePlay::getNewLocationResources(int hero) {
    // declare variables
    int r = 0;
    int clm = 0;
    string tile_type = "";
    int money = 0;
    int army = 0;
    int place = 0;
    bool t = false;
    
    // for loop that runs through the heroes in the game
    for (int i = 0; i < numHeroes; i++) {
        // if the hero is empty continue 
        if (h[i].getHeroName() == "") continue;
        // get hero's location
        r = h[i].getRow();
        clm = h[i].getColumn();
        // get the hero's name
        //cout << h[i].getHeroName() << endl;
        // if that check if the location has been adventured already
        if (h[i].getAdventured(r, clm) == true) {
            //cout << "ALREADY GOT RESOURCES" << endl;
            continue;
        }
        // all else
        else {
            // if that checks if the user
            if (h[i].getHeroName() == h[hero].getHeroName()) {
                cout << "You have traveled on new land." << endl;    
            }
            
            // get the tile type at location 
            tile_type = map[r][clm];
            // check what tile type location is and give the user money (maybe soldiers) from location
            if (tile_type == "w") {
                money = 10;
                h[i].setMoney(true, money);
                if (h[i].getHeroName() == h[hero].getHeroName()) {
                    cout << "You gain $10." << endl;    
                }
            }
            // water tile
            else if (tile_type == "p") {
                money = 20;
                army = 10;
                h[i].setMoney(true, money);
                h[i].setArmySize(true, army);
                if (h[i].getHeroName() == h[hero].getHeroName()) {
                    cout << "You gain $10 and 20 more knights." << endl;
                }
            }
            // city tile
            else {
                // for loop that runs through the Cities class and compares the cities letters to the tile type
                for (int a = 0; a < 26; a++) {
                    // if that checks if the letter is the tile type
                    if (tile_type == c[a].getLetter()) {
                        // set the place to where the letter is in the city array 
                        place = a;
                        // break out of for loop
                        break;
                    }
                }
                // set the money equal to the money associated with that city
                money = c[place].getCityMoney();
                // set the army equal to the army associated with that city
                army = c[place].getCityArmy();
                // add the city money to the hero
                h[i].setMoney(true, money);
                // add the city army to the hero
                h[i].setArmySize(true, army);
                
                // if that checks if the turns are more than 0 and if the i value in loop is the user
                if (getTurns() > 0 && i == hero) {
                    // declare variables
                    string option = "";
                    int choice = 0;
                    
                    // output messages
                    cout << "You have arrived in " << c[place].getCityName() << ". Do you want to listen to rumors?" << endl;
                    cout << "0. Yes" << endl;
                    cout << "1. No" << endl;
                    // allow user to choose option
                    cin >> option;
                    // while loop that checks if the user input is a number
                    // if not a number, ask the user to keep entering in option
                    while (t == false) {
                        for (int a = 0; a < option.length(); a++) {
                            if (isalpha(option[a])) {
                                cout << "Please enter in a value 0-1: ";
                                cin >> option;
                                t = false;
                            }
                            else {
                                // convert option to choice
                                choice = stoi(option);
                                // while loop that runs as long as the choice is not in range
                                if (choice > 1 or choice < 0) {
                                    cout << "Please enter in a value 0-1: ";
                                    cin >> option;
                                    t = false;
                                }
                                else {
                                    t = true;
                                    break;
                                }
                            }
                        }    
                    }
                    t = false;
                    
                    // if the choice is 0 (yes)
                    if (choice == 0) {
                        // declare variables
                        int distance = 0;
                        int smallest_distance = 10000;
                        int closest_hero = 0;
                        int opp_r = 0;
                        int opp_c = 0;
                        
                        // for loop that runs through the heros in game
                        for (int d = 0; d < numHeroes; d++) {
                            // decalre variables
                            int opp_r = h[d].getRow();
                            int opp_c = h[d].getColumn();
                            // if that checks to make sure user is not compared to self
                            if (opp_r == r && opp_c == clm) continue;
                            // set distance to equation
                            distance = abs(r - opp_r) + abs(clm - opp_c);
                            // if that checks if the new distance is smaller than the overall smallest distance
                            if (distance < smallest_distance) {
                                // if distance is smaller, make distance the new smaller value
                                smallest_distance = distance;
                                // set the place in the array of the closest hero
                                closest_hero = d;
                            }
                        }
                        // output the closest player to user
                        cout << h[closest_hero].getHeroName() << " is " << smallest_distance << " moves away." << endl;
                    }
                    
                    // output messages
                    cout << "You have arrived in " << c[place].getCityName() << ". Do you want to buy more knights?" << endl;
                    cout << "0. Yes" << endl;
                    cout << "1. No" << endl;
                    // allow user to choose option
                    cin >> option;
                    // for loop that checks if the user input is a number
                    // if not a number, ask the user to keep entering in option
                    while (t == false) {
                        for (int a = 0; a < option.length(); a++) {
                            if (isalpha(option[a])) {
                                cout << "Please enter in a value 0-1: ";
                                cin >> option;
                                t = false;
                            }
                            else {
                                // convert option to choice
                                choice = stoi(option);
                                // while loop that runs as long as the choice is not in range
                                if (choice > 1 or choice < 0) {
                                    cout << "Please enter in a value 0-1: ";
                                    cin >> option;
                                    t = false;
                                }    
                                else {
                                    t = true;
                                    break;
                                }
                            }
                        }    
                    }
                    t = false;
                    
                    if (choice == 0) {
                        if (h[hero].getMoney() < 0) {
                            cout << "You do not have any money to buy more knights with." << endl; 
                        }
                        cout << "You have $" << h[hero].getMoney() << "." << endl;
                        cout << "How many knights would you like to buy? (1 Knight = $20)" << endl;
                        cin >> option;
                        // for loop that checks if the user input is a number
                        // if not a number, ask the user to keep entering in option
                        for (int a = 0; a < option.length(); a++) {
                            while (isalpha(option[a])) {
                                cout << "Please enter in a value 0-1: ";
                                cin >> option;
                            }
                        }
                        // convert option to choice
                        choice = stoi(option);
                        
                        int purchase = 20 * choice;
                        
                        // if that checks if the hero can handle the purchase
                        if (h[hero].getMoney() - purchase < 0) {
                            cout << "You do not have enough money to buy that many knights" << endl;
                        }
                        // all else
                        else {
                        // make purcahse
                        h[hero].setMoney(false, purchase);
                        cout << "You spent $" << purchase << endl;
                        h[hero].setArmySize(true, choice);
                        
                        // output message
                        cout << "You have purchased " << choice << " knights." << endl; 
                        cout << "You have $" << h[hero].getMoney() << " after that purchase." << endl;
                        cout << "Your army is now " << h[hero].getArmySize() << " knights." << endl;
                        }
                        
                    }
                } 
            }
            // set adventured land
            h[i].setAdventured(r, clm);
        }
        // cout << h[i].getHeroName() << " money amount is " << h[i].getMoney() << endl;
        // cout << h[i].getHeroName() << " army size is " << h[i].getArmySize() << endl;
    
    }
}


/* function that checks if the location a warrior or hero is at has dragonglass
    - for loop that runs through all the heroes in the game
        * takes their location and uses those variables in dragonglass array
    - if the location has dragonglass, give it to a warrior of a hero  
        * warrior can only hold one piece
    - for loop that runs through all the warriors in the game
        * takes the location of the warrior and uses those variables in dragonglass array
    - if the location has dragonglass, give the warrior the dragonglass

    return: none
    output: none
*/
void gamePlay::getCheckDragonglass(int hero) {
    // declare variables
    int r = 0;
    int c = 0;
    string option = "";
    int choice = 0;
    bool t = false;
    
    for (int i = 0; i < numHeroes; i++) {
        // set the row and column of the hero to variables
        r = h[i].getRow();
        c = h[i].getColumn();
        
        // if that checks if the location of the hero is a location where dragonglass is
        if (dp_locations[r][c] == true) {
            // if that checks if the user has landed on dragonglass and they have a warrior
            if (i == hero && h[hero].getNumWarriors() != 0) {
                cout << "Great news! You have stumbled upon Dragonglass." << endl;
                cout << "Choose which one of your warriors would you like to equip with Dragonglass (enter their name or number): " << endl;
                h[hero].getNamesofWarriors();
                // allow user to choose option
                cin >> option;
                // for loop that checks if the user input is a number
                // if not a number, ask the user to keep entering in option
                while (t == false) {
                    for (int a = 0; a < option.length(); a++) {
                        if (isalpha(option[a])) {
                            cout << "Please enter in a value 0-" << h[hero].getNumWarriors() << ": ";
                            cin >> option;
                            t = false;
                        }
                        else {
                            // convert option to choice
                            choice = stoi(option);
                            // while loop that runs as long as the choice is not in range
                            if (choice > h[hero].getNumWarriors() or choice < 0) {
                                cout << "Please enter in a value 0-" << h[hero].getNumWarriors() << ": ";
                                cin >> option;
                                t = false;
                            }
                            else {
                                t = true;
                                break;
                            }
                        }
                    }    
                }
                t = false;

                dp_locations[r][c] = false;
                cout << "Location has dragonglass: " << dp_locations[r][c] << endl;
                h[hero].setWarriorWithDragonglass(choice);
                
            }
        }
        // for the other players in the game
        else if (dp_locations[r][c] == true) {
            // if that checks if the hero has warriros
            if (h[i].getNumWarriors() != 0) {
                // get the number of warriors with hero
                int num = h[i].getNumWarriors() - 1;
                Warriors warrior;
                // get random warriro
                int random_warrior = random() % num + 1;
                warrior = h[i].getCertainWarrior(random_warrior);
                // set the warrior with the dragonglass
                h[i].setWarriorWithDragonglass(random_warrior);
                // set the location to no more dragonglass
                dp_locations[r][c] = false;
                // cout << "Location has dragonglass: " << dp_locations[r][c] << endl;
                // cout << h[i].getHeroName() << " has found dragonglass." << endl;
                // cout << warrior.getWarriorsName() << " now holds the dragonglass." << endl;
            }
        }
    }
    
    // TEST
    // for (int a = 0; a < numWarriors; a++) {
    //     r = w[a].getRow();
    //     c = w[a].getColumn();    
        
    //     if (dp_locations[r][c] == true && w[a].getFree() == "yes") {
    //         dp_locations[r][c] = false;
    //         cout << "Location has dragonglass: " << dp_locations[r][c] << endl;
    //         w[a].setDragonglass("yes");
    //         cout << w[a].getWarriorsName() << "found dragonglass." << endl;
    //     }
    // }
}


/* function that lets the user travel 
    - ask the user which direction they want to go
    - take the input and move player that direction
        * check barriers of the map
        * check if the user can go on water
        
    return: none
    output: none
*/


void gamePlay::getTravel(int hero) {
    // if the user has chosen to travel, take the direction they have inputed
    // and move that hero that direction
    // update the players row and column in the Hero class
    
    // declare variables
    bool ship = h[hero].getShip();
    string choice = "";
    int num = 0;
    int move = 1;
    int r = h[hero].getRow();
    int c = h[hero].getColumn();
    int new_row = 0;
    int new_column = 0;
    bool t = false;
    
    // output message
    cout << "In which direction will you travel:" << endl;
    cout << "0. North" << endl;
    cout << "1. East" << endl;
    cout << "2. South" << endl;
    cout << "3. West" << endl;
    cin >> choice;
    while (t == false) {
        for (int a = 0; a < choice.length(); a++) {
            if (isalpha(choice[a]) or choice == "") {
                cout << "Please enter in a value 0-3: ";
                cin >> choice;
                t = false;
            }
            else {
                num = stoi(choice);
                if (num > 3 or num < 0) {
                    cout << "Please enter in a value 0-3: ";
                    cin >> choice;
                    t = false;
                }
                else {
                    t = true;
                    break;
                }
            }
        }    
    }
    t = false;
    
    // if the choice was North
    if (num == 0) {
        // subtract one from the row (go up)
        new_row = r - move;
        // if the new row value is within the map
        if (new_row <= 24 && new_row >= 0) {
            // if that checks if the user has a ship and if the new tile is water
            if (map[new_row][c] == "w" && ship == false) {
                // call get Travel again
                cout << "You do not have a ship to go on water. Choose another direction." << endl;
                getTravel(hero);
            }
            // all else
            else {
                // update the location for hero
                h[hero].setRow(new_row);
            }
            // cout << "New position" << endl;
            // cout << "(" << h[hero].getRow() << ", " << h[hero].getColumn() << ")" << endl;
        }
        // all else (off the map values)
        else {
            // call function again
            cout << "You cannot move off the map, choose another direction." << endl;
            getTravel(hero);
        }
    }
    // else if the hero wants to move East
    else if (num == 1) {
        // add one to the users column
        new_column = c + move;
        // check if new value is within map
        if (new_column <= 15 && new_column >= 0) {
            // if that checks if the user has a ship and if the new tile is water
            if (map[r][new_column] == "w" && ship == false) {
                // call get Travel again
                cout << "You do not have a ship to go on water. Choose another direction." << endl;
                getTravel(hero);    
            }
            // all else
            else {
                // update location
                h[hero].setColumn(new_column);    
            }
            // cout << "New position" << endl;
            // cout << "(" << h[hero].getRow() << ", " << h[hero].getColumn() << ")" << endl;
        }
        // all else
        else {
            // call get travel again
            cout << "You cannot move off the map, choose another direction." << endl;
            getTravel(hero);    
        }
    }
    // else if the hero wants to move South
    else if (num == 2) {
        // add one to the row
        new_row = h[hero].getRow() + move;
        // check to see if within map 
        if (new_row <= 24 && new_row >= 0) {
            // if that checks if the user has a ship and if the new tile is water
            if (map[new_row][c] == "w" && ship == false) {
                // call get travel again
                cout << "You do not have a ship to go on water. Choose another direction." << endl;
                getTravel(hero);
            }
            // all else
            else {
                // update location
                h[hero].setRow(new_row);
            }
            // cout << "New position" << endl;
            // cout << "(" << h[hero].getRow() << ", " << h[hero].getColumn() << ")" << endl;
        }
        // all else
        else {
            // call get travel again
            cout << "You cannot move off the map, choose another direction." << endl;
            getTravel(hero);
        }
    }
    // else if the user wwnats to travel West 
    else if (num == 3) {
        // subtract one from column
        new_column = h[hero].getColumn() - move;
        // if that checks if the column is within map
        if (new_column <= 15 && new_column >= 0) {
            // if that checks if the user has a ship and if the new tile is water
            if (map[r][new_column] == "w" && ship == false) {
                // call get travel again
                cout << "You do not have a ship to go on water. Choose another direction." << endl;
                getTravel(hero);    
            }
            // all else
            else {
                // update location
                h[hero].setColumn(new_column);    
            }
            // cout << "New position" << endl;
            // cout << "(" << h[hero].getRow() << ", " << h[hero].getColumn() << ")" << endl;
        }
        // all else
        else {
            // call get travel 
            cout << "You cannot move off the map, choose another direction." << endl;
            getTravel(hero);    
        }
    }
}


/* function that rests for a turn
    - keeps the user in the same position
    - updates users warrior's strength
    
    return: none
    output: none
*/
void gamePlay::getRest(int hero) {
    // the location for the hero remains unchanged
    // each warrior in ther hero's party increases their strength by 1
    
    cout << "Each of your warrior's strength has increased by 1 from resting." << endl;
    
    // declare variables
    int add = 1;
    int num_w = h[hero].getNumWarriors();
    
    for (int i = 0; i < num_w; i++) {
        h[hero].setAddWarriorStrength(i, add);
    } 
    
    
}

/* function that has user stay in position and increase each warrior's morale by 1
    return: none
    output: none
*/

void gamePlay::getGodTalk(int hero) {
    // the location of the hero remains unchanged
    // each warrior in the hero's party increases their morale by 1
    
    // declare variables
    int add = 1;
    int num_w = h[hero].getNumWarriors();
    
    cout << "Each of your warrior's morale has increased by 1 from consulting with God." << endl;
    
    // add one to morale for each warrior
    for (int i = 0; i < num_w; i++) {
        h[hero].setAddWarriorMorale(i, add);
    } 
}

// function that moves the other players
// calls other functions 
void gamePlay::getMovePlayers(int hero) {
    // for loop that runs through all the heroes and moves them
    for (int i = 0; i < numHeroes; i++) {
        if (i == hero) continue;
        getMoveHeroesLocation(i);
    }
    
    // for loop that runs through all warriors and moves them
    for (int a = 0; a < numWarriors; a++) {
        if (w[a].getFree() == "no") continue;
        getMoveWarriorsLocation(a);
    }
}

/* function that lets other heroes travel 
    - choose which direction by random
    - take the location and move player that direction
        * check barriers of the map
        * check if the user can go on water
        
    return: none
    output: none
*/
void gamePlay::getMoveHeroesLocation(int hero) {
    // declare variables
    bool ship = h[hero].getShip();
    int num = random() % 3 + 1;
    int move = 1;
    int new_row = 0;
    int new_column = 0;
    // set the hero's row and column in variables
    int r = h[hero].getRow();
    int c = h[hero].getColumn();
    
    // if that checks if the move is North 
    if (num == 0) {
        // get the new row (using row because moving North)
        new_row = r - move;
        // if that checks if the new row is within the map
        if (new_row <= 24 && new_row >= 0) {
            // if that checks if the new tile is water and if the hero has no ship 
            // allows the hero not to move onto water if they do not have a ship
            if (map[new_row][c] == "w" && ship == false) {
                // ouptut message
                // call the function again to get a different valid move
                getMoveHeroesLocation(hero);
            }
            // all else
            else {
                // if they do have a ship then move the player
                h[hero].setRow(new_row);
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveHeroesLocation(hero);
        }
    }
    // else if that checks if the move is East
    else if (num == 1) {
        // set the new column position
        new_column = c + move;
        // if that checks if the new column is valid in the map
        if (new_column <= 15 && new_column >= 0) {
            // if that checks if the new tile is water and if the hero has no ship 
            // allows the hero not to move onto water if they do not have a shi
            if (map[r][new_column] == "w" && ship == false) {
                // call function again to get a valid move
                getMoveHeroesLocation(hero); 
            }
            else {
                // set the hero's new location
                h[hero].setColumn(new_column);    
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveHeroesLocation(hero);  
        }
    }
    else if (num == 2) {
        // get the new row (using row because moving South)
        new_row = r + move;
        // if that checks if the new row is within the map
        if (new_row <= 24 && new_row >= 0) {
            // if that checks if the new tile is water and if the hero has no ship 
            // allows the hero not to move onto water if they do not have a ship
            if (map[new_row][c] == "w" && ship == false) {
                // call the function again to get a different valid move
                getMoveHeroesLocation(hero);
            }
            // all else
            else {
                // if they do have a ship then move the player
                h[hero].setRow(new_row);
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveHeroesLocation(hero);
        }
    }
    else if (num == 3) {
        // set the new column position
        new_column = c - move;
        // if that checks if the new column is valid in the map
        if (new_column <= 15 && new_column >= 0) {
            // if that checks if the new tile is water and if the hero has no ship 
            // allows the hero not to move onto water if they do not have a shi
            if (map[r][new_column] == "w" && ship == false) {
                // call function again to get a valid move
                getMoveHeroesLocation(hero);   
            }
            else {
                // set the hero's new location
                h[hero].setColumn(new_column);    
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveHeroesLocation(hero);   
        }
    }
}


/* function that lets other warriors travel 
    - choose which direction by random
    - take the location and move warrior that direction
        * check barriers of the map
        * check if the user can go on water
        
    return: none
    output: none
*/
void gamePlay::getMoveWarriorsLocation(int warrior) {
    // declare variables
    bool ship = w[warrior].getShip();
    int num = random() % 3 + 1;
    int move = 1;
    int new_row = 0;
    int new_column = 0;
    // set the hero's row and column in variables
    int r = w[warrior].getRow();
    int c = w[warrior].getColumn();
    
    
    // if that checks if the move is North 
    if (num == 0) {
        // get the new row (using row because moving North)
        new_row = r - move;
        // if that checks if the new row is within the map
        if (new_row <= 24 && new_row >= 0) {
            // output message
            // cout << "Old Position" << endl;
            // cout << "(" << w[warrior].getRow() << ", " << w[warrior].getColumn() << ")" << endl;
            // if that checks if the new tile is water and if the warrior has no ship 
            // allows the hero not to move onto water if they do not have a ship
            if (map[new_row][c] == "w" && ship == false) {
                // check if they are stranded in the water and move them to a land tile
                if (map[r + 1][c] == "w" && ship == false && w[warrior].getFree() == "yes") {
                    if (map[r][c + 1] == "w" && ship == false) {
                        if (map[r][c - 1] == "w" && ship == false) {
                            r = random() % 24 + 1;
                            c = random() % 15 + 1;
                            while (map[r][c] == "w") {
                                r = random() % 24 + 1;
                                c = random() % 15 + 1;
                            }
                            w[warrior].setRow(r);
                            w[warrior].setColumn(c);
                        }
                    }
                }
                else {
                    // call function again to get a valid move
                    getMoveWarriorsLocation(warrior);     
                }
            }
            // all else
            else {
                // if they do have a ship then move the player
                w[warrior].setRow(new_row);
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveWarriorsLocation(warrior);  
        }
    }
    // else if that checks if the move is East
    else if (num == 1) {
        // set the new column position
        new_column = c + move;
        // if that checks if the new column is valid in the map
        if (new_column <= 15 && new_column >= 0) {
            // if that checks if the new tile is water and if the user has no ship 
            // allows the hero not to move onto water if they do not have a shi
            if (map[r][new_column] == "w" && ship == false) {
                // check if they are stranded in the water and move them to a land tile
                if (map[r + 1][c] == "w" && ship == false && w[warrior].getFree() == "yes") {
                    if (map[r - 1][c] == "w" && ship == false) {
                        if (map[r][c - 1] == "w" && ship == false) {
                            r = random() % 24 + 1;
                            c = random() % 15 + 1;
                            while (map[r][c] == "w") {
                                r = random() % 24 + 1;
                                c = random() % 15 + 1;
                            }
                            w[warrior].setRow(r);
                            w[warrior].setColumn(c);
                        }
                    }
                }
                else {
                    // call function again to get a valid move
                    getMoveWarriorsLocation(warrior);     
                }
            }
            else {
                // set the hero's new location
                w[warrior].setColumn(new_column);    
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveWarriorsLocation(warrior);   
        }
    }
    else if (num == 2) {
        // get the new row (using row because moving South)
        new_row = r + move;
        // if that checks if the new row is within the map
        if (new_row <= 24 && new_row >= 0) {
            // if that checks if the new tile is water and if the user has no ship 
            // allows the hero not to move onto water if they do not have a ship
            if (map[new_row][c] == "w" && ship == false) {
                // check if they are stranded in the water and move them to a land tile
                if (map[r - 1][c] == "w" && ship == false && w[warrior].getFree() == "yes") {
                    if (map[r][c + 1] == "w" && ship == false) {
                        if (map[r][c - 1] == "w" && ship == false) {
                            r = random() % 24 + 1;
                            c = random() % 15 + 1;
                            while (map[r][c] == "w") {
                                r = random() % 24 + 1;
                                c = random() % 15 + 1;
                            }
                            w[warrior].setRow(r);
                            w[warrior].setColumn(c);
                        }
                    }
                }
                else {
                    // call function again to get a valid move
                    getMoveWarriorsLocation(warrior);     
                }
            }
            // all else
            else {
                // if they do have a ship then move the player
                w[warrior].setRow(new_row);
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveWarriorsLocation(warrior);  
        }
    }
    else if (num == 3) {
        // set the new column position
        new_column = c - move;
        // if that checks if the new column is valid in the map
        if (new_column <= 15 && new_column >= 0) {
            // if that checks if the new tile is water and if the user has no ship 
            // allows the hero not to move onto water if they do not have a shi
            if (map[r][new_column] == "w" && ship == false) {
                // check if they are stranded in the water and move them to a land tile
                if (map[r + 1][c] == "w" && ship == false && w[warrior].getFree() == "yes") {
                    if (map[r - 1][c] == "w" && ship == false) {
                        if (map[r][c + 1] == "w" && ship == false) {
                            r = random() % 24 + 1;
                            c = random() % 15 + 1;
                            while (map[r][c] == "w") {
                                r = random() % 24 + 1;
                                c = random() % 15 + 1;
                            }
                            w[warrior].setRow(r);
                            w[warrior].setColumn(c);
                        }
                    }
                }
                else {
                    // call function again to get a valid move
                    getMoveWarriorsLocation(warrior);     
                }
            }
            else {
                // set the hero's new location
                w[warrior].setColumn(new_column);    
            }
        }
        else {
            // call the function again to get a different valid move
            getMoveWarriorsLocation(warrior);  
        }
    }   
}


/* function that determines if a random event needs to happen
    - use random generator to determine if event will happen
    - uses random to generate number between 100
    - choose an event based on random number generated
    - call other functions based on event to change variables

    return: none
    output: none
*/
void gamePlay::getRandomEvent(int hero) {
    // 30% chance that one random event happens
    
    // Choices:
        // Drought
        // Deserters
        // Jackpot
        // Kindness
    
    
    // declare variables
    int prob = 0;
    prob = random() % 100 + 1;
    // if that checks if the prob is less than or equal to 30
    if (prob <= 30) {
        // generate new prob
        prob = random() % 100 + 1;
        
        // if the prob is less than or equal to 25
        // call Drought event
        if (prob <= 25) {
            // drought will happen
            cout << "Bad news:" << endl;
            cout << "There has been no rain in days and your army has very little food left." << endl;
            cout << "Your warrior's morale and strength have decreased." << endl;
            h[hero].getDrought();
        }
        // else if 
        // call Deserters
        else if (prob > 25 && prob <= 50) {
            if (turns > 5) {
                //Deserters
                cout << "Bad news:" << endl;
                cout << "This campaign is taking a very long time and the soldiers are tired and sad." << endl;
                cout << "Some decide to leave." << endl;
                cout << "Your warrior's loyalty have decreased." << endl;
                
                //cout << "OG Army: " << h[hero].getArmySize() << endl;
                h[hero].setArmySize(false, 10);
                //cout << "New Army: " << h[hero].getArmySize() << endl;
                h[hero].getDeserters();
            }
        }
        // else if that calls Jackpot 
        // adds money to user
        else if (prob > 50 && prob <= 75) {
            // Jackpot
            cout << "Good news:" << endl;
            cout << "Your heroic cause has won the hearts of many noble and wealthy benefactors!" << endl;
            cout << "They generously donate funds for your cause." << endl;
            cout << endl;
            
            //cout << "OG money: " << h[hero].getMoney() << endl;
            int cash = h[hero].getMoney();
            if (cash > 0) {
                cash = cash * -1;
            }
            h[hero].setMoney(true, cash); 
            cout << "New money: " << h[hero].getMoney() << endl;
        }
        // else that calls Kindness
        else {
            // Kindness
            cout << "Good news:" << endl;
            cout << "You have decided to offer shelter to some refugees." << endl;
            cout << "Your army size is larger and your warrior's loyalty increases." << endl;
            
            //cout << "OG Army: " << h[hero].getArmySize() << endl;
            h[hero].setArmySize(true, 10);
            cout << "New Army: " << h[hero].getArmySize() << endl;
            h[hero].getKindness();
        }
    }
}

/* function that gest the set events in the game
    - if the turn in the game is 10 call events
        * Daenerys gets Dragon
        * Stannis dies
        * Sansa gets Arya
        * Cersei gets Jamie

    return: none
    output: messages based on events
*/
void gamePlay::getSetEvents(int hero) {
    // check whether the events that conditioned to happen need to occur
    
    // if that checks if the turn is 10
    if (turns == 10) {
        // declare variables
        string name = "Daenerys Targaryen";
        int her = -1;
        string ship = "no";
        Warriors removed_w;
        int place = -1;
        
        // Daenerys aquires a dragon after every 10 turns
        // find Daenerys in hero array
        for (int i = 0; i < numHeroes; i++) {
            if (name == h[i].getHeroName()) {
                her = i;   
            }
            
            // if she is alive, set a Dragon as one of her warriors
            if (her != -1) {
                if (h[her].getNumWarriors() < 4) {
                    if (h[her].getShip() == true) {
                        ship = "yes";
                    }
                    // make Dragon as Warrior object and set to Daenerys
                    Warriors Dragons = {"Dragons", 180, 100, 80,"no", ship, "no"};
                    h[her].setWarriors(Dragons);
                    h[her].setArmySize(true, 5000);
                     h[her].getNamesofWarriors();
                    // cout << endl;
                }
                // else that removes a warrior from her if she has 4 to take Dragon
                // Dragon eats warrior
                else {
                    removed_w = h[her].getCertainWarrior(3);
                    for (int a = 0; a < numWarriors; a++) {
                        if (removed_w.getWarriorsName() == w[a].getWarriorsName()) {
                            place = a;
                        }
                    }
                    
                    // move the heroes in the warrior array to account for the eaten warrior
                    for (int d = place; d < numWarriors; d++) {
                        w[d] = w[d+1];
                    }
                    // subtract one from the total amount of warriors
                    setNumWarriors(numWarriors - 1);
                        
                    Warriors Dragons = {"Dragons", 198, 110, 88,"no", ship, "no"};
                    h[her].setDragons(Dragons);
                    h[her].setArmySize(true, 5000);
                    h[her].getNamesofWarriors();
                }
            }
        }
        
        
        // Stannis dies
        // declare variables
        place = -1;
        name = "Stannis Baratheon";
        char respect = ' ';
        
        // for loop that finds Stannis
        for (int i = 0; i < numHeroes; i++) {
            if (name == h[i].getHeroName()) {
                place = i;   
                break;
            }
        }
        // if found, remove him from game and ask user to pay respects
        if (place > -1) {
            if (hero == place) {
                setContinueGame(false);
            }
            else {
                cout << "Stannis Baratheon has retired. Press F to pay respects." << endl;
                cin >> respect;
                respect = toupper(respect);
                
                // moves heroes in hero array to account for Stannis removal
                for (int d = place; d < numHeroes; d++) {
                    h[d] = h[d+1];
                }
                
                numHeroes = numHeroes - 1;
                
                while (respect != 'F') {
                    cout << "Have you no respect?! Press F to pay respects." << endl;
                    cin >> respect;
                    respect = toupper(respect);
                }
                
                cout << "Mood." << endl;
            }
        }
        
        // Arya to Sansa 
        place = -1;
        Warriors Arya;
        name = "Sansa Stark";
        //cout << "Heroes: (SET EVENTS)" << endl;
        for (int i = 0; i < numHeroes; i++) {
            if (h[i].getHeroName() == "") continue;
            //cout << h[i].getHeroName() << endl;
        }
        //cout << endl;
        
        // for loop that runs through heroes to find Sansa
        for (int i = 0; i < numHeroes; i++) {
            if (name == h[i].getHeroName()) {
                // set place for Sansa
                place = i;   
                // set name to Arya
                name = "Arya Stark";
                break;
            }
        }
        
        if (place > -1) {
            // run through the heroes to get rid of Arya in their group if they hold her
            for (int a = 0; a < numHeroes; a++) {
                if (a == place) continue;
                h[a].getCheckArya();
            }
            
            // for loop that runs to find which warrior is Arya
            for (int b = 0; b < numWarriors; b++) {
                if (name == w[b].getWarriorsName()) {
                    w[b].setFree("no");
                    Arya = w[b];
                    break;
                }
            }
            
            // set Arya to Sansa
            h[place].setArya(Arya);
            //cout << "Sansa to Arya" << endl;
            //cout << h[place].getHeroName() << endl;
            //h[place].getNamesofWarriors();
        }
            
        // Cersei loses Jamie
        name = "Cersei Lannister";
        place = -1;
        int place_w = -1;
        
        
        // for loop that runs through heroes to find Cersei
        for (int i = 0; i < numHeroes; i++) {
            if (name == h[i].getHeroName()) {
                // set place for Cersei
                place = i;
                break;
            }
        }
        
        // if Cersei is alive
        if (place > -1) {
            //cout << "Cersei's Warriors" << endl;
            //h[place].getNamesofWarriors();
            //cout << endl;
            name = "Jaime Lannister";
            
            
            // for loop that runs through heroes to find Cersei
            for (int i = 0; i < numWarriors; i++) {
                if (name == w[i].getWarriorsName()) {
                    // set place for Cersei
                    place_w = i;
                    //cout << "Found Cersei" << endl;
                    break;
                }
            }
            
            // if Jamie is found
            // remove Jamie from Cersei
            // give Jamie new location
            if (place_w > -1) {
                h[place].getLoseJamie();
                int random_r = random() % 24 + 1;
                int random_c = random() % 15 + 1;
                while (map[random_r][random_c] == "w") {
                    random_r = random() % 24 + 1;
                    random_c = random() % 15 + 1;
                }
                w[place_w].setRow(random_r);
                w[place_w].setColumn(random_c);
                //h[place].getNamesofWarriors();
            }
        }
    }
}


/* function that checks if the White Walker battle needs to happen
    - if test is true tell user White Walkers are approaching
    - ask user if they want to battle
    - if they do not choose to battle continue the game and add one to the deny
        * if they deny 5 times, end the game
    - calculate a proabability the user will win by using varaibles
    - show if the winner won or not
    - end game
    
    returns: none
    output: messages
            win/lose
*/
void gamePlay::getWhiteWalkers(int hero) {
    
    // declare variables   
    int count = h[hero].getNumControlLand(hero);
    string choice = "";
    int answer = -1;
    float power_score = 0;
    float add_power_score = 0;
    Warriors hero_warrior;
    int w_strength = 0;
    int w_morale = 0;
    int h_influence = 0;
    int num_cities = 0;
    int cities = 0;
    bool control_city = false;
    float prob = 0;
    bool t = false;
    
    
    // change to 50 after testing
    // Call the white walker based on if:
        // turns is 50
        // user army size is 2000
        // count is greater than 200
        // users points are 400
        // user is only hero left
    if (turns == 12 || h[hero].getArmySize() >= 2000 || count > 200 || h[hero].getPoints() == 400 || numHeroes == 1) {
        cout << "Sad news! The White Walkers are approaching our location. Would you like to battle them now?:" << endl;
        cout << "0. Yes" << endl;
        cout << "1. No" << endl;
        // user input
        cin >> choice;
        
        // for and while loop that tests the users answer
        while (t == false) {
            for (int a = 0; a < choice.length(); a++) {
                if (isalpha(choice[a])) {
                    cout << "Please enter in a value 0-1: ";
                    cin >> choice;
                    t = false;
                }
                else {
                    answer = stoi(choice);
                    if (answer > 1 or answer < 0) {
                        cout << "Please enter in a value 0-1: ";
                        cin >> choice;
                        t = false;
                    }    
                    else {
                        t = true;
                        break;
                    }
                }
            }    
        }
        t = false;
        
        // if that checks if the user wants to battle or not
        if (answer == 0) {
            // get all the power score add ons from the hero and their warriors
            power_score = h[hero].getArmySize();
            //cout << "Army Size: " << power_score << endl;
            
            for (int a = 0; a < h[hero].getNumWarriors(); a++) {
                // get the hero's warrior
                hero_warrior = h[hero].getCertainWarrior(a);
                
                // get the warrior's strength
                w_strength = hero_warrior.getStrength();
                //cout << "Warriors Strength: " << w_strength << endl;
                // get the warrior's morale
                w_morale = hero_warrior.getMorale();
                //cout << "Warriors Morale: " << w_morale << endl;
                // calculate the hero's power score based on warrior
                add_power_score = (w_strength * w_morale) / 50;
                //cout << "Warrior's add on power score: " << add_power_score << endl;
                // add the warrior's effect to the power score
                power_score = power_score + add_power_score;
                //cout << "Overall power score: " << power_score << endl;
                
                if (hero_warrior.getDragonglass() == "yes") {
                    power_score = power_score + 10000;
                }
                
            }
            
            // get the hero's influence
            h_influence = h[hero].getInfluence();
            //cout << "Hero's Influence: " << h_influence << endl;
            
            // for loop that finds the number of cities the hero controls
            for (int r = 0; r < 25; r++) {
                for (int c = 0; c < 16; c++) {
                    if (map[r][c] != "p" && map[r][c] != "w") {
                        control_city = h[hero].getCheckCity(r, c);
                        if (control_city == true) {
                            num_cities++;
                        }
                    }
                }
            }
            
            // add to the power score using variables
            add_power_score = ((num_cities + 1) * h_influence) / 4;
            power_score = power_score + add_power_score;
            prob = 1 - exp(-power_score/30000);
            prob = prob * 100;
            // output the users probability
            cout << "Winning score out of 100: " << prob << endl;
            // if prob greater than 50 
            if (prob > 50) {
                // end game
                cout << "Congratulations! You have defeated the White Walkers!" << endl;
                setContinueGame(false);
            }
            // if score less than or equal to 50
            else {
                // end game
                cout << "The White Walkers have defeated you." << endl;
                setContinueGame(false);
            }
        }
        // else (deny)
        else {
            // add one to deny
            deny++;
            // if the user denied to many times 5+
            if (deny == 5) {
                cout << "You denied too many times. You lose the game." << endl;
                setContinueGame(false);
            }
            else {
                cout << "Deny:" << deny << endl;
            }
        }
    }
}

// function that determines if the game continue or not
void gamePlay::setContinueGame(bool w_l) {
    // if the varaible is false, end the game
    if (w_l == false) {
        lost_or_win = false;
    }
    // else continue game
    else {
        lost_or_win = true;
    }
}

// returns continue game
bool gamePlay::getContinueGame() {
    return lost_or_win;
}

// function that takes the user's points for the game and enters them into a text file
// if previous text is in there, add that text in a vector
// then output the vector then add the new section
void gamePlay::getRecordGame(int hero, bool self_made, string user_name, string file) {
    // declare variables
    string name = "";
    string line = "";
    int count = 0;
    vector <string> v;
    int points  = h[hero].getPoints();
    
    // if that checks if the user made a hero or not
    if (self_made == false) {
        name = h[hero].getHeroName();   
    }
    else {
        name = "Self";
    }
    
    // open stream file to read text
    ifstream myfile;
    myfile.open(file);
    
    // if statement that checks of text file is open
    if (myfile.is_open()) {
        // while loop that runs through each line of text file
        while (getline(myfile, line)) {
            
            // if statement that checks if the line is empty and to move onto next line
            if (line.empty()) continue;
            v.push_back(line);
        }
        
    }
    // close file
    myfile.close();
    
    // stream file to ouptut text
    ofstream myfiletwo;
    myfiletwo.open(file);
    
    // for loop that outputs vector
    for (int a = 0; a < v.size(); a++) {
        myfiletwo << v[a] << endl;
    }
    
    // output new section
    myfiletwo << left << setw(20) << user_name << left << setw(40) << name << left << setw(20) << points << endl;  
    myfiletwo.close();
}

// adds one to the turn of the game
void gamePlay::setTurns() {
    turns++;
}

// return turns
int gamePlay::getTurns() {
    // cout << "Army Size: " << h[hero].getArmySize() << endl;
    // cout << "Money: " << h[hero].getMoney() << endl;
    // cout << "Points: " << h[hero].getPoints() << endl;
    return turns;
} 

// set the hero's username
void gamePlay::setUsersHeroName(int hero_place) {
    usersHeroName = h[hero_place].getHeroName();
}

// returns the postion the user's player is at in array
int gamePlay::getUsersHeroPosition() {
    for (int i = 0; i < numHeroes; i++) {
        if (usersHeroName == h[i].getHeroName()) {
            return i;
        }
    }
}