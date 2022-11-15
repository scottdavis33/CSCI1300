// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Class Player
#include <iostream>
#include "Player.h"
#include <cstdlib>
#include <string>
using namespace std;
/*
Psedocode for Player default constructor
1. set string to be empty
2. set fullness to 50 (each player)
3. set bool to true
*/
Player::Player()
{
    fullness_ = 50; // respected fullness for each player
    name_ = ""; // will be prompted for all 5 players
    life_ = true; // initail will be set to true unless they die
}
/*
Psedocode for parameterized constructor
1. Set private variables to parameters
*/
Player::Player(int fullness, string name, bool life)
{
    fullness_ = fullness;
    name_ = name;
    life_ = life;
}
/*
Pseudocode for the getters()
1. return the private variables
*/
int Player::getFullness()
{
    return fullness_;
}
string Player::getName()
{
    return name_;
}
bool Player::getLife()
{
    return life_;
}

// Pseudocode for the setters (fullness, Name, life)
// 1. set private variables to parameters

void Player::setLife(bool life)
{
    life_ = life;
}
int Player::setFullness(int fullness)
{
    fullness_ = fullness;
}
void Player::setName(string name)
{
    name_ = name;
}
/*
Psuedocode movement
1. Using a random number to get the probability of each player move
2. If it == 4 then we need to take 1 from their fullness
*/
void Player::movement()
{
    if(rand()%5 == 2)
    {
        fullness_ = fullness_ - 1;
    }
}
