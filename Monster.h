// CSCI 1300 Fall 2022
// Author: Scott Davis
// Recitation: 308 – Baljot Kaur
// Project 3 - Class 3

#include <iostream>
#ifndef Monster_H
#define Monster_H
using namespace std;

// Will include objects for all the monsters, each monster will have different levels of power 
// and will have different probabilities to kill player/ party members

class Monster
{
// Monster class objects
private:

    int level_;

    string name_;
// Monster class member functions
public:

    Monster();

    Monster(string name, int level);

    Monster(string name, int level, Monster monsters[]);

    void setLevel(int level);

    int getLevel();

    void setName(string name);

    string getName();

};
#endif

