// CSCI 1300 Fall 2022
// Author: Scott Davis
// Recitation: 308 – Baljot Kaur
// Project 3 - Class 4
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
    int weapon_ = 0;
    bool armor_;

public:
    // default and parameterized constructor
    Player();
    Player(int fullness_, string name_, bool life_);
    
    // Getters
    int getFullness();
    void addFullness();
    string getName();
    bool getLife();
    
    // Setters
    void setName(string name);
    void setLife(bool life);
    void setFullness(int fullness);
    int getWeapon();
    void setWeapon(int);
    // for moving each individual player
    void movement();
    void setArmor(bool);
    bool checkArmor();
    void invest();
    void door();

};
#endif
