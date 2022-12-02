// CSCI 1300 Fall 2022
// Author: Scott Davis
// Recitation: 308 – Baljot Kaur
// Project 3 - Class 3
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Group.h"
#include <string>

using namespace std;

// sets the name to a blank string and the level to 0
Monster::Monster()
{
    name_ = "";
    level_ = 0;
}
// sets the monsters name and level to inputted parameters
Monster::Monster(string name, int level)
{
    name_ = name;
    level_ = level;
}
//sets level
void Monster::setLevel(int level)
{
    level_ = level;
}
//returns level
int Monster::getLevel()
{
    return level_;
}
//sets monster name
void Monster::setName(string name)
{
    name_ = name;
}
// returns monster name
string Monster::getName()
{
    return name_;
}

