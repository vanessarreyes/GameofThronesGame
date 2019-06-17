// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#include <iostream>
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Warriors.h"
#include "Heroes.h"
#include "gamePlay.h"
#include "Battle.h"
using namespace std;

int main() {
    
    vector<gamePlay> Games;
    int game_num = 0;
    
    srand(123);
    int y_or_no = 0;
    
    while(y_or_no == 0) {
        bool t = false;
        gamePlay new_game;
        Games.push_back(new_game);
        string play_again = "";
        string user_name = "";
        string choose_hero;
        int selection = 0;
        string amount = "";
        int money = 0;
        int influence = 0;
        int army_size = 0;
        int row = 0;
        int column = 0;
        string num = "";
        int choice = 0;
        int hero_num = 0;
        bool end_game = false;
        bool own_user = false;
        
        
        // import map
        //cout << "MAP" << endl;
        Games[game_num].getMap("mapGOT.txt");
        
        //cout << endl;
        
        // import cities
        //cout << "CITIES" << endl;
        Games[game_num].getCitiesInfo("citiesGOT.txt");
        
        //cout << endl;
        
        // import warriors
        //cout << "WARRIORS" << endl;
        Games[game_num].getWarriors("warriorsGOT.txt");
        //cout << "Number of Warriors: " << Games[game_num].getNumWarriors() << endl;
        
        //cout << endl;
        
        // import heroes
        //cout << "HEROES" << endl;
        Games[game_num].getHeroes("heroesGOT.txt");
        //cout << "Number of Heroes: " << Games[game_num].getNumHeroes() << endl;
        
        //cout << endl;
        
        // set the warrior location 
        //cout << "SET WARRIORS LOCATION" << endl;
        Games[game_num].setWarriorsToHeroLocation();
        
        //cout << endl;
        
        // set free warrior's locations
        //cout << "SET FREE WARRIORS" << endl;
        Games[game_num].setFreeWarriors();
        
        //cout << endl;
    
        // import text files and upload them to necessary classes
        
        // start the game
        // create a loop that runs through a game if the player wants to play
    
        cout << "Welcome to the G A M E of T H R O N E S!" << endl;
        cout << "====================================================================================================" << endl;
        cout << "The objective of the game is to build your army and control as much land as you can." << endl;
        cout << "As you play you will battle other heroes and have warriors join your army." << endl;
        cout << "Be careful of the White Walkers." << endl;
        cout << "The resources you obtain from playing will help you in the final battle agianst the White Walkers." << endl;
        cout << "====================================================================================================" << endl;
        cout << endl;
        cout << "State your name, Your Grace: " << endl;
        // get users input
        cin >> user_name;
        
        // ask user what hero they want
        cout << "Would you like to choose a hero " << user_name << ", Your Grace? " << endl;
        cout << "0. Yes" << endl;
        cout << "1. No" << endl;
        cin >> choose_hero;
        
        while (t == false) {
            for (int a = 0; a < choose_hero.length(); a++) {
                if (isalpha(choose_hero[a])) {
                    cout << "Please enter in 0-1" << endl;
                    cin >> choose_hero;
                    t = false;
                }
                else {
                    selection = stoi(choose_hero);
                    if (selection > 1 or selection < 0) {
                        cout << "Please enter in 0-1" << endl;
                        cin >> choose_hero;
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
        
        if (selection == 0) {
            cout << "Please choose from the following heroes: " << endl;
            cout << "0. Cersei Lannister" << endl;
            cout << "1. Stannis Baratheon" << endl;
            cout << "2. Jon Snow" << endl;
            cout << "3. Sansa Stark" << endl;
            cout << "4. Euron Greyjoy" << endl;
            cout << "5. Daenerys Targaryen" << endl;
            cin >> num;
            
            while (t == false) {
                for (int a = 0; a < num.length(); a++) {
                    if (isalpha(num[a]) or num == "") {
                        cout << "Please enter a number between 0-5." << endl;
                        cout << "Please choose from the following heroes: " << endl;
                        cout << "0. Cersei Lannister" << endl;
                        cout << "1. Stannis Baratheon" << endl;
                        cout << "2. Jon Snow" << endl;
                        cout << "3. Sansa Stark" << endl;
                        cout << "4. Euron Greyjoy" << endl;
                        cout << "5. Daenerys Targaryen" << endl;
                        cin >> num;
                        t = false;
                    }
                    else {
                        hero_num = stoi(num);
                        if (hero_num > 5 or hero_num < 0) {
                            cout << "Please enter a number between 0-5." << endl;
                            cout << "Please choose from the following heroes: " << endl;
                            cout << "0. Cersei Lannister" << endl;
                            cout << "1. Stannis Baratheon" << endl;
                            cout << "2. Jon Snow" << endl;
                            cout << "3. Sansa Stark" << endl;
                            cout << "4. Euron Greyjoy" << endl;
                            cout << "5. Daenerys Targaryen" << endl;
                            cin >> num;
                            t = false;
                        }
                        else {
                            t = true;
                        }
                    }
                }
            }
            
            t = false;
            
            Games[game_num].setNumHeroes(6);
            Games[game_num].setUsersHeroName(hero_num);
        }
        else if (selection == 1) {
            
            cout << "Your Grace " << user_name << ", you have chosen to go on this journey alone." << endl;
            cout << "Please provide starting values for your adventure." << endl;
            
            //The starting values for money, influence and army size can be between 0 and 10000
            // For starting location, the user has to choose a valid row value (1-25) and a valid column
            // value (1-16).
            // If the hero’s chosen starting location is on ‘water’, equip the hero with a ship; they will
            // have from the beginning the ability to move to ‘water’ locations on the map.
            // The location cannot be the same as one of the other 6 heroes or as one of the
            // already-initialized warriors.
            cout << "Money (0-1000): ";
            cin >> amount;
            
            while (t == false) {
                for (int a = 0; a < choose_hero.length(); a++) {
                    if (isalpha(amount[a])) {
                        cout << "Please enter in a valid value 0-1000: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        money = stoi(amount);
                        if (money > 1000 or money < 0) {
                            cout << "Please enter in a valid value 0-1000: ";
                            cin >> amount;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }
            }    
                
            t = false;
            
            cout << "Influence (0-1000): ";
            cin >> amount;
            
            
            while (t == false) {
                for (int a = 0; a < choose_hero.length(); a++) {
                    if (isalpha(amount[a])) {
                        cout << "Please enter in a valid value 0-1000: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        influence = stoi(amount);
                        if (influence > 1000 or influence < 0) {
                            cout << "Please enter in a valid value 0-1000: ";
                            cin >> amount;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }
            }
            t = false;
        
            cout << "Army Size (0-1000): ";
            cin >> amount;
            
            while (t == false) {
                for (int a = 0; a < choose_hero.length(); a++) {
                    if (isalpha(amount[a])) {
                        cout << "Please enter in a valid value 0-1000: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        army_size = stoi(amount);
                        if (army_size > 1000 or army_size < 0) {
                            cout << "Please enter in a valid value 0-1000: ";
                            cin >> amount;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }
            }
            t = false;
            
            cout << "Starting row (1-25): ";
            cin >> amount;
            
            while (t == false) {
                for (int a = 0; a < choose_hero.length(); a++) {
                    if (isalpha(amount[a])) {
                        cout << "Please enter in a value 1-25: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        row = stoi(amount);
                        if (row > 25 or row < 1) {
                            cout << "Please enter in a value 1-25: ";
                            cin >> amount;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }
            }
            t = false;
            row = row - 1;
            
            cout << "Starting column (1-16): ";
            cin >> amount;
            
             while (t == false) {
                for (int a = 0; a < choose_hero.length(); a++) {
                    if (isalpha(amount[a])) {
                        cout << "Please enter in a value 1-25: ";
                        cin >> amount;
                        t = false;
                    }
                    else {
                        column = stoi(amount);
                        if (column > 16 or column < 1) {
                            cout << "Please enter in a value 1-25: ";
                            cin >> amount;
                        }
                        else {
                            t = true;
                            break;
                        }
                    }
                }
            }
            t = false;
            column = column - 1;
            
            Games[game_num].setUserHero(user_name, money, influence, army_size, row, column);
            hero_num = 6;
            //cout << "Number of Heroes: " << Games[game_num].getNumHeroes() << endl;
            own_user = true;
        }
    
        //cout << endl;
        
        //cout << "LOCATION/POINTS" << endl;
        Games[game_num].getLocationPoints();
        
        while(end_game == false) {
            
            // display the map to the user based on starting position
            // call gamePlay class getMninMap
            cout << endl;
            cout << "MINIMAP" << endl;
            Games[game_num].getMiniMap(hero_num);
                
            cout << "Please choose what you want to do:" << endl;
            cout << "0. Travel" << endl;
            cout << "1. Rest" << endl;
            cout << "2. Consult with the gods" << endl;
            cin >> num;
            while (t == false) {
                for (int a = 0; a < num.length(); a++) {
                    if (isalpha(num[a])) {
                        cout << "Please enter in a value 0-2: ";
                        cin >> num;
                        t = false;
                    }
                    else {
                        choice = stoi(num);
                        if (choice > 2 or choice < 0) {
                            cout << "Please enter in a value 0-2: ";
                            cin >> num;
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
                Games[game_num].getTravel(hero_num);
                //cout << "SET WARRIORS LOCATION" << endl;
                Games[game_num].setWarriorsToHeroLocation();
                //cout << endl;
                
                //cout << "UPDATE WARRIORS" << endl;
                Games[game_num].getUpdateWarriors();
                //cout << endl;
            }
            else if (choice == 1) {
                Games[game_num].getRest(hero_num);
            }
            else if (choice == 2) {
                Games[game_num].getGodTalk(hero_num);
            }
            
            //cout << "MOVE OTHERS" << endl;
            Games[game_num].getMovePlayers(hero_num);
            //cout << endl;
            
            // move all the heroes and the free warriors to new locations
            
            // checks if battle needs to happen
            //cout << "SURROUNDINGS" << endl;
            Games[game_num].getSurroundings(hero_num);
            
            //cout << "GAME END??" << endl;
            if (Games[game_num].getContinueGame() == false) {
                Games[game_num].getRecordGame(hero_num, own_user, user_name, "resultsGOT.txt");
                // record the user performance and enter into a text file
                end_game == true;
                break;
            }
            
            if (own_user == true) {
                hero_num = Games[game_num].getNumHeroes() - 1;
            }
            else {
                hero_num = Games[game_num].getUsersHeroPosition();
            }
            
            //cout << "UPDATE WARRIORS" << endl;
            Games[game_num].getUpdateWarriors();
            //cout << endl;
        
            //cout << "OTHER SURROUNDINGS" << endl;
            Games[game_num].getCheckOthersSurroundings(hero_num);
            
            if (own_user == true) {
                hero_num = Games[game_num].getNumHeroes() - 1;
            }
            else {
                hero_num = Games[game_num].getUsersHeroPosition();
            }
            
            //cout << "UPDATE WARRIORS" << endl;
            Games[game_num].getUpdateWarriors();
            //cout << endl;
            
            //cout << "NEARBY WARRIORS" << endl;
            Games[game_num].getCheckNearWarriors(hero_num);
            //cout << endl;
            
            //cout << "UPDATE WARRIORS" << endl;
            Games[game_num].getUpdateWarriors();
            //cout << endl;
            
            //cout << "DRAGONGLASS CHECK" << endl;
            Games[game_num].getCheckDragonglass(hero_num);
            //cout << endl;
            
            // check if the new location was previously controlled
            // add that new location to controlled
            // since they traveled, add the points associated with the new location
           // cout << "LOCATION POINTS" << endl;
            Games[game_num].getLocationPoints();
            //cout << endl;
            
            //cout << "LOCATION RESOURCES" << endl;
            Games[game_num].getNewLocationResources(hero_num);
            
            //cout << endl;
            
            //cout << "SET WARRIORS LOCATION" << endl;
            Games[game_num].setWarriorsToHeroLocation();
            
            //cout << "UPDATE WARRIORS" << endl;
            Games[game_num].getUpdateWarriors();
           // cout << endl;
            
            //cout << "RANDOM EVENTS" << endl;
            Games[game_num].getRandomEvent(hero_num);
            //cout << endl;
            
            //cout << "SET EVENTS" << endl;
            Games[game_num].getSetEvents(hero_num);
            //cout << endl; 
            
            //cout << "GAME END??" << endl;
            if (Games[game_num].getContinueGame() == false) {
                Games[game_num].getRecordGame(hero_num, own_user, user_name, "resultsGOT.txt");
                // record the user performance and enter into a text file
                end_game == true;
                break;
            }
            else {
                //cout << "YOU'RE STILL ALIVE" << endl;
                cout << endl;
            }
            
            if (own_user == true) {
                hero_num = Games[game_num].getNumHeroes() - 1;
            }
            else {
                hero_num = Games[game_num].getUsersHeroPosition();
            }
            
            //cout << "UPDATE WARRIORS" << endl;
            Games[game_num].getUpdateWarriors();
            //cout << endl;
            
            //cout << "WHITE WALKERS" << endl;
            Games[game_num].getWhiteWalkers(hero_num);
            //cout << endl;
            
            if (Games[game_num].getContinueGame() == false) {
                Games[game_num].getRecordGame(hero_num, own_user, user_name, "resultsGOT.txt");
                // record the user performance and enter into a text file
                end_game == true;
                break;
            }
            
            //cout << "TURN UPDATE" << endl;
            Games[game_num].setTurns();
            cout << "Game Turn: " << Games[game_num].getTurns() << endl;
            //cout << endl;
                
        }
        
        // end of the game
        // ask user if they want to play again
        
        cout << "Do you want to play again: (0-1) " << endl;
        cout << "0. Yes" << endl;
        cout << "1. No" << endl;
        cin >> play_again;
        game_num++;
        
        while (t == false) {
            for (int a = 0; a < play_again.length(); a++) {
                if (isalpha(play_again[a])) {
                    cout << "Please enter in a value 0-1: ";
                    cin >> play_again;
                    t = false;
                }
                else {
                    y_or_no = stoi(play_again);
                    if (y_or_no > 1 or y_or_no < 0) {
                        cout << "Please enter in a value 0-1: ";
                        cin >> play_again;
                        t = false;
                    }    
                    else {
                        t = true;
                    }
                }
            }    
        }
    }
    return 0;
}
