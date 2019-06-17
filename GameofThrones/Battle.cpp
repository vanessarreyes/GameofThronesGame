// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #3 - Game of Thrones

#include "Battle.h"

/*  Speech
    - take in two hero objects that represent the opponents    
    - compute the probability that the user will win using variables with that user
    - if the probability is less than 100, the user loses
        * they lose half influence
    - if the probability is 100, then the user wins
        * the opponent retires and is out of the game
        * the winner then gets money, influence, army, and warriors from the defeated hero
    - set the winner variable to true or false depending on whether the user won or not
    - output messages letting the user know if they lost or not
    - return the user as an object of hero class with new variables set
*/
Heroes Battle::getSpeech(Heroes user_hero, Heroes opponent) {
    // declare variables
    int money = 0;
    int influence = 0;
    int army = 0;
    float morale = 0;
    float hero_i = 0;
    float prob = 0;
    int num_w_user = 0;
    int num_w_opp = 0;
    Warriors aquired_h;
    
    
    // get first warriors morale
    morale = user_hero.getAddWarriorMorale(0);
    // get the hero's influence
    hero_i = user_hero.getInfluence();
    // calculate the probability with other variables
    prob = ((100 - morale) * hero_i)/ 160000;
    // make prob not decimal value
    prob = prob * 100;
    
    //TEST
    // cout << "Morale: " << morale << endl;
    // cout << "Influence " << hero_i << endl;
    // cout << "Probability: " << prob << endl;
    // cout << endl;
    
    // if that checks if the prob is less than 100
    if (prob < 100) {
        // output message
        cout << "You lost the encounter. You lost half of your influence." << endl;
        // set the hero's influence to half of what it was
        hero_i = hero_i / 2;
        //cout << "hero_i: " << hero_i << endl;
        user_hero.setInfluence(false, hero_i);
        //cout << "Influence: " << user_hero.getInfluence() << endl;
        // set winner to false since player lost speech
        winner = false;
        // return the user's hero with updated variables
        return user_hero;
        
    }
    // if the user won
    else {
        // output message
        cout << "You have defeated " << opponent.getHeroName() << "." << endl;
        cout << opponent.getHeroName() << " has retired." << endl;
        
        // give the winner the losing heroes money, influence, army, and warriors
        
        // get the opponents money value
        money = opponent.getMoney();
        //cout << "OG Money: " << user_hero.getMoney() << endl;
        // add the opponents money to the winner
        user_hero.setMoney(true, money);
        //cout << "Updated Money: " << user_hero.getMoney() << endl;
        // get the opponents influence
        influence = opponent.getInfluence();
        //cout << "OG Influence: " << user_hero.getInfluence() << endl;
        // add the opponents influence to winner's influence
        user_hero.setInfluence(true, influence);
        //cout << "Updated Influence: " << user_hero.getInfluence() << endl;
        // get opponents army size
        army = opponent.getArmySize();
        //cout << "OG Army: " << user_hero.getArmySize() << endl;
        // add the opponents army size to the winner
        user_hero.setArmySize(true, army);
        //cout << "Updated Army: " << user_hero.getArmySize() << endl;
        
        // get the opponents and winners number of warriors
        num_w_user = user_hero.getNumWarriors();
        num_w_opp = opponent.getNumWarriors();
        
        // for loop that runs through each warrior for the opponent
        for (int i = 0; i < num_w_opp; i++) {
            // get the opponent's warrior
            aquired_h = opponent.getCertainWarrior(i);
            // if the winner has less than 4 warriors, add the opponents warrior
            if (num_w_user < 4) {
                // call set warrior function
                user_hero.setWarriors(aquired_h);
                num_w_user++;
            }
            // all else
            else {
                // call set warrior funcion
                // will ask the user if they want to replace their current warrior's with their opponent's warriors
                user_hero.setWarriors(aquired_h);
            }
        }
        
        // TEST
        // display the hero's warriors after the winning speech
        // num_w_user = user_hero.getNumWarriors();
        // for (int i = 0; i < num_w_user; i++) {
        //     aquired_h = user_hero.getCertainWarrior(i);
        //     cout << aquired_h.getWarriorsName() << endl;    
        // }
        // cout << endl;
        
        // set the winner to true
        winner = true;
        // return the winner object 
        return user_hero;
        
    }
}

/* Buy Out
    - take in two hero objects that represent the opponents    
    - compute the probability that the user will win using variables with that user
    - if the probability is less than 100, the user loses
        * they lose half influence
    - if the probability is 100, then the user wins
        * the opponent retires and is out of the game
        * the winner then gets money, influence, army, and warriors from the defeated hero
    - set the winner variable to true or false depending on whether the user won or not
    - output messages letting the user know if they lost or not
    - return the user as an object of hero class with new variables set

*/
Heroes Battle::getBuyOut(Heroes user_hero, Heroes opponent) {
    // declare variables
    int num_w_user = 0;
    int num_w_opp = 0;
    int money = 0;
    int influence = 0;
    int army = 0;
    float money_user = user_hero.getMoney();
    Warriors opp_first_w = opponent.getCertainWarrior(0);
    float loyalty_w_opp = opp_first_w.getLoyalty();
    float prob = 0;
    Warriors aquired_h;
    
    // TEST
    // cout << "Money: " << money_user << endl;
    // cout << "Loyalty: " << loyalty_w_opp << endl;
    
    // compute the probability using variables
    prob = ((100 - loyalty_w_opp) * money_user) / 1780000;
    prob = prob * 100;
    
    // if that checks if the probability is less than 100
    if (prob < 100) {
        // output messages
        cout << "You lost the encounter. You lost half of your money." << endl;
        
        // make the user's money value half
        money_user = money_user / 2;
        //cout << "money_user: " << money_user << endl;
        user_hero.setMoney(false, money_user);
        //cout << "Money: " << user_hero.getMoney() << endl;
        
        // set winner to false because user lost
        winner = false;
        // return the updated variables for user
        return user_hero;
    }
    // if the user wins
    else {
        // output messages
        cout << "You have defeated " << opponent.getHeroName() << "." << endl;
        cout << opponent.getHeroName() << " has retired." << endl;
        
        // give the winner the losing heroes money, influence, army, and warriors
        // get the opponents money 
        money = opponent.getMoney();
        //cout << "OG Money: " << user_hero.getMoney() << endl;
        // give the user the opponents money
        user_hero.setMoney(true, money);
        //cout << "Updated Money: " << user_hero.getMoney() << endl;
        
        // get the opponents influence
        influence = opponent.getInfluence();
        //cout << "OG Influence: " << user_hero.getInfluence() << endl;
        // give the user the opponents influence
        user_hero.setInfluence(true, influence);
        //cout << "Updated Influence: " << user_hero.getInfluence() << endl;
        
        // get the opponents army size
        army = opponent.getArmySize();
        //cout << "OG Army: " << user_hero.getArmySize() << endl;
        // give the user the opponents army
        user_hero.setArmySize(true, army);
        //cout << "Updated Army: " << user_hero.getArmySize() << endl;
        
        // get the user and opponents number of warriors
        num_w_user = user_hero.getNumWarriors();
        num_w_opp = opponent.getNumWarriors();
        
        // for loop that runs through the opponents warrior's
        for (int i = 0; i < num_w_opp; i++) {
            // get the opponents warrior 
            aquired_h = opponent.getCertainWarrior(i);
            // if the user has less than 4 warriors, set the opponents warrior to next empty position
            if (num_w_user < 4) {
                // call set warriors function with warrior object
                user_hero.setWarriors(aquired_h);
                num_w_user++;
            }
            // if the user has 4 warriors
            else {
                // call function
                // will ask user what warrior they want to replace if they want to
                user_hero.setWarriors(aquired_h);
            }
        }
        
        // TEST
        // display the hero's warriors after the winning speech
        // num_w_user = user_hero.getNumWarriors();
        // for (int i = 0; i < num_w_user; i++) {
        //     aquired_h = user_hero.getCertainWarrior(i);
        //     cout << aquired_h.getWarriorsName() << endl;    
        // }
        // cout << endl;
        
        // set the winner true
        winner = true;
        // return the user with updated varaibles
        return user_hero;
    }
}

/* Battle
    - takes in two hero's to battle with
    - First checks if both the hero's have no warriors
        * if they both do not have any warriors, then compare their army size
        * whoever has the larger army will win
        * the loser will retire
        * the winner will get the other hero's money, influence, army size, and warriors
    - Next, the function will test if the one hero has warriors and the other doesn't
        * the warrior that does not have a warrior will lose
        * the loser will retire
        * the winner will get the other hero's money, influence, army size, and warriors
    - Next the function will compute a probability with the hero's variables (strength and warrior strength)
        * if the probability of one hero is less than 100, the other hero will win
        * if the probability is 100, then the hero with the probability will win
        * the loser will retire
        * the winner will get the other hero's money, influence, army size, and warriors
    - the function will set the winner variable to true or false based on if the user is battling or not
        * if the user is battling and loses, then the winner will be set to false to end game
        * if the user is not playing, then winner will always be true to contineu game
    - the function will then return the winning hero with the updated variables
*/

Heroes Battle::getBattlePlay(Heroes user_hero, Heroes opponent, bool user) {
    // declare varaibles
    int num_w_user = 0;
    int num_w_opp = 0;
    int money = 0;
    int influence = 0;
    int army = 0;
    Warriors aquired_h;
    int num_user_warriors = user_hero.getNumWarriors();
    int num_opp_warriors = opponent.getNumWarriors();
    int army_user = user_hero.getArmySize();
    int army_opp = opponent.getArmySize();
    int w_strength_user = 0;
    int w_strength_opp = 0;
    
    // if that checks if both the hero's have no warrior
    if (num_user_warriors == 0 && num_opp_warriors == 0) {
        // if they both do not have any warriors, then compare their army size
        // if else that checks who has the larger army size and will be winner
        if (army_user > army_opp) {
            // output message
            cout << "You have defeated " << opponent.getHeroName() << "." << endl;
            cout << opponent.getHeroName() << " has retired." << endl;
            
            // give the winner the losing heroes money, influence, army, and warriors
            // get opponent's money =
            money = opponent.getMoney();
            //cout << "OG Money: " << user_hero.getMoney() << endl;
            // give the winner the opponent's money
            user_hero.setMoney(true, money);
            //cout << "Updated Money: " << user_hero.getMoney() << endl;
            
            // get the opponents influence
            influence = opponent.getInfluence();
            //cout << "OG Influence: " << user_hero.getInfluence() << endl;
            // give the winner the opponent's influence
            user_hero.setInfluence(true, influence);
            //cout << "Updated Influence: " << user_hero.getInfluence() << endl;
            
            // get the opponent's army size
            army = opponent.getArmySize();
            // cout << "OG Army: " << user_hero.getArmySize() << endl;
            // give the winner the opponent's army
            user_hero.setArmySize(true, army);
            // cout << "Updated Army: " << user_hero.getArmySize() << endl;
            
            // get the number of warrior's for each hero
            num_w_user = user_hero.getNumWarriors();
            num_w_opp = opponent.getNumWarriors();
            
            // for loop that runs throught the opponent's warriors 
            for (int i = 0; i < num_w_opp; i++) {
                // get the opponent's warrior
                aquired_h = opponent.getCertainWarrior(i);
                // if that checks if the user has less than 4 warriors
                if (num_w_user < 4) {
                    // call set warrior function
                    user_hero.setWarriors(aquired_h);
                    num_w_user++;
                }
                // if they have more than 4 warriors
                else {
                    // call set warriors function
                    user_hero.setWarriors(aquired_h);
                }
            }
            
            // TEST
            // num_w_user = user_hero.getNumWarriors();
            // for (int i = 0; i < num_w_user; i++) {
            //     aquired_h = user_hero.getCertainWarrior(i);
            //     cout << aquired_h.getWarriorsName() << endl;    
            // }
            // cout << endl;
            
            // set the winner to true
            winner = true;
            // return the user with their updated values
            return user_hero;
        }
        // else if that checks if the user lost
        else if (army_user < army_opp) {
            // output message
            cout << "You lost the encounter." << endl;
            // set winner to false to end game
            winner == false;
            // return the user with updated variables
            return user_hero;
        }
    }
    // all else
    else {
        // declare variables
        string choice = "";
        int num_choice = 0;
        Warriors user_warrior;
        Warriors opp_warrior;
        int user_army = user_hero.getArmySize();
        int opp_army = opponent.getArmySize();
        
        // if that checks if the user is battling
        if (user == true) {
            // if that checks if hero has warriors
            // if they do not, they lose
            if (user_hero.getNumWarriors() == 0) {
                cout << "You have no warriors to battle with." << endl;
                cout << "You lose the battle." << endl;
                // set winner to false to end game
                winner = false;
                // return the user with updated varaibles
                return user_hero;
            }
            
            // output message
            cout << "Which of your warriors will represent you in battle:" << endl;
            // output the hero's warriors
            user_hero.getNamesofWarriors();
            // allow user to enter in option
            cin >> choice;
            // for loop that runs through the user's answer
            for (int a = 0; a < choice.length(); a++) {
                // while loop that runs if the string has an alphabet letter
                while (isalpha(choice[a])) {
                    cout << "Please enter in a value: (0-" << user_hero.getNumWarriors() << ")" << endl;
                    // allow user to enter in choice
                    cin >> choice;
                }
            }
            // convert the string to int
            num_choice = stoi(choice);
            // while loop that runs if the integer is not in range
            while (num_choice > user_hero.getNumWarriors() or num_choice < 0) {
                cout << "Please enter in a value 0-1: ";
                cin >> choice;
                num_choice = stoi(choice);
            }
            
            // get the warrior that user asks for 
            user_warrior = user_hero.getCertainWarrior(num_choice);
            
            // if that checks if the opponent has only one warrior
            // if they do, get the warrior
            if (opponent.getNumWarriors() == 1) {
                opp_warrior = opponent.getCertainWarrior(0);
            }
            // all else
            else {
                // get a raondom warrior for opponent
                opp_warrior = opponent.getCertainWarrior(random() % (opponent.getNumWarriors() - 1) + 1);
            }
            
            //cout << "Opponent Warrior: " << opp_warrior.getWarriorsName() << endl;
            
            // get the strength from both warriors
            int user_w_strength = user_warrior.getStrength();
            int opp_w_strength = opp_warrior.getStrength();
            
            // get the probability for both heroes
            int user_prob = user_army * user_w_strength;
            int opp_prob = opp_army * opp_w_strength;
            
            // if else that tests which hero had the higher prob to win
            if (user_prob > opp_prob) {
                // output message
                cout << "You have defeated " << opponent.getHeroName() << "." << endl;
                cout << opponent.getHeroName() << " has retired." << endl;
                
                // give the winner the losing heroes money, influence, army, and warriors
                money = opponent.getMoney();
                user_hero.setMoney(true, money);
                influence = opponent.getInfluence();
                user_hero.setInfluence(true, influence);
                army = opponent.getArmySize();
                user_hero.setArmySize(true, army);
                //
                
                // get number of warriors for both heroes
                num_w_user = user_hero.getNumWarriors();
                num_w_opp = opponent.getNumWarriors();
                //
                
                // for loop that runs through the opponents heroes
                for (int i = 0; i < num_w_opp; i++) {
                    // get the opponents warrior
                    aquired_h = opponent.getCertainWarrior(i);
                    // if that checks if the user has less than 4 warriors
                    if (num_w_user < 4) {
                        // call function to set warrior in next emoty position
                        user_hero.setWarriors(aquired_h);
                        num_w_user++;
                    }
                    // all else
                    else {
                        // call set warriors function
                        user_hero.setWarriors(aquired_h);
                    }
                }
                // set the winner to true
                winner = true;
                // return the user with update variables
                return user_hero;
            }
            // all else
            else {
                // otput message 
                cout << "Your warrior and army were no match." << endl;
                cout << "You lost the encounter." << endl;
                // set winner to false
                winner = false;
                // return the hero
                return user_hero;
            }
        }
        // if the user is not battling
        else if (user == false) {
            
            // check if one of the hero's has no warriors, they lose
            if (user_hero.getNumWarriors() == 0) {
                // winner to true so game continues (not user battle)
                winner = true;
                // return winning hero
                return opponent;
            }
            
            // check if the other hero does not have any warriors, they lose
            if (opponent.getNumWarriors() == 0) {
                // winner to true so game continues (not user battle)
                winner = true;
                // return the winning hero
                return user_hero;
            }
            
            // random number
            num_choice = random() % (user_hero.getNumWarriors() - 1) + 1;
            
            if (user_hero.getNumWarriors() == 1) {
                user_warrior = user_hero.getCertainWarrior(0);
            }
            else {
                // get a random warrior for hero
                user_warrior = user_hero.getCertainWarrior(num_choice);    
            }

            if (opponent.getNumWarriors() == 1) {
                opp_warrior = opponent.getCertainWarrior(0);
            }
            else {
                // get random warrior for hero
            opp_warrior = opponent.getCertainWarrior(random() % (opponent.getNumWarriors() - 1) + 1);    
            }
            
            // get both warrior's strength 
            int user_w_strength = user_warrior.getStrength();
            int opp_w_strength = opp_warrior.getStrength();
            
            // get both hero's probabilities
            int user_prob = user_army * user_w_strength;
            int opp_prob = opp_army * opp_w_strength;
            
            // if that checks if who has the higher prob
            if (user_prob > opp_prob) {
                cout << opponent.getHeroName() << " has retired." << endl;
                
                // give the winner the losing heroes money, influence, army, and warriors
                money = opponent.getMoney();
                user_hero.setMoney(true, money);
                influence = opponent.getInfluence();
                user_hero.setInfluence(true, influence);
                army = opponent.getArmySize();
                user_hero.setArmySize(true, army);
                //
                
                // get the number of warrior's for both hero's
                num_w_user = user_hero.getNumWarriors();
                num_w_opp = opponent.getNumWarriors();
                //
                
                // for loop that runs through the losing hero's warriors
                for (int i = 0; i < num_w_opp; i++) {
                    // get losing hero's warrior
                    aquired_h = opponent.getCertainWarrior(i);
                    // if that checks if winner has less than 4 warriors
                    if (num_w_user < 4) {
                        // if that checks if the winning hero has 4 warriors
                        if (num_w_user == 4) {
                            // break
                            break;
                        }
                        // add the warrior to winning hero
                        user_hero.setWarriors(aquired_h);
                        // add one to the total warriors hero has
                        num_w_user++;
                    }
                }
                
                // set the winner to true (continue game)
                winner = true;
                // return the updated hero
                return user_hero;
            }
            else {
                // output message
                cout << user_hero.getHeroName() << " has retired." << endl;
                
                // give the winner the losing heroes money, influence, army, and warriors
                money = user_hero.getMoney();
                opponent.setMoney(true, money);
                influence = user_hero.getInfluence();
                opponent.setInfluence(true, influence);
                army = user_hero.getArmySize();
                opponent.setArmySize(true, army);
                //
                
                // get number of warriors for both heroes
                num_w_user = user_hero.getNumWarriors();
                num_w_opp = opponent.getNumWarriors();
                //
                
                // for loop that runs through losing hero's warriors
                for (int i = 0; i < num_w_user; i++) {
                    // get losing hero's warrior
                    aquired_h = user_hero.getCertainWarrior(i);
                    // if that checks if the winning warrior has less than 4 warriors
                    if (num_w_opp < 4) {
                        if (num_w_opp == 4) {
                            // break
                            break;
                        }
                        // give losing hero's warrior to winner
                        user_hero.setWarriors(aquired_h);
                        // add one to warriors total
                        num_w_opp++;
                        // if that checks if the total warriors is 4
                    }
                }
                
                // set the winner to true (continue game)
                winner = true;
                // return updated winner
                return opponent;
                
            }
        }
    }
}

// return the winner (false/true)
bool Battle::getWinner() {
    return winner;
}