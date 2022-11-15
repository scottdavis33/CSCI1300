// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Class Player
#include <iostream>
#ifndef Player_H
#define Player_H
using namespace std;

/*
Pseudocode Player Class
1. Make your private variables that you will need
2. Get your public functions
3. Up and running
*/

class Player
{
// Player Objects
private:

    int fullness_;
    string name_;
    bool life_;

public:
    // default and parameterized constructor
    Player();
    Player(int fullness_, string name_, bool life_);
    
    // Getters
    int getFullness();
    string getName();
    bool getLife();
    
    // Setters
    void setName(string name);
    void setLife(bool life);
    int setFullness(int fullness);
    // for moving each individual player
    void movement();

};
#endif
