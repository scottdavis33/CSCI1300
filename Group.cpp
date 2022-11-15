// CSCI 1300 Fall 2022
// Author: Scott Davis
// Recitation: 308 – Baljot Kaur
// Project 3 - Class 1

#include <iostream>
#include "Group.h"
#include "Player.h"
#include "Map.h"
using namespace std;
/*
Pseudocode for groupmove
1. Pulling for Players class
2. Integrating it with Group
3. Each array is filled with the movement of each player
*/
void Group::groupmove()
{
    players[0].movement();
    players[1].movement();
    players[2].movement();
    players[3].movement();
    players[4].movement();
}
/*
getName and getFull Pseduocode
1. return the players array to each index with the getName function
*/
string Group::getName(int index)
{
    return players[index].getName();
}

// int Group::getFull(int index)
// {
//     return players[index].getFull();
// }
/*
Pseudocode set Full
*/