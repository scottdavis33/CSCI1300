// CSCI 1300 Fall 2022
// Author: Scott Davis && Jared Preyer 
// Recitation: 308 – Baljot Kaur && Recitation 105 Raegan Rychecky
// Project 3 - Class 1
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Monster.h"
#ifndef Group_H
#define Group_H
using namespace std;
/*
Psedocode Group
1. There will be 6 functions in public
2. One array of Players set at size 5 in private
3. Refer to .cpp for further Pseudocode
*/
class Group
{
    public:
        void groupmove();
        void life(Map);
        void Investigate(Map);
         //getters
         string getName(int index);
         int getFull(int index);
         // setters
         void setFullandName();
         


    private:

        Player players[5];
};
#endif
