// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Class Group

#include <iostream>
#include "Group.h"
#include "Player.h"
#include "Map.h"
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;
//sets armor to 0
//sets bonus points to 0
Group::Group()
{
    armor_ = 0;
    bonus_ = 0;
}
//prompts player to input his name and his players names
//updates player name, group names and fullnesses accordingly
void Group::setFullandName()
{
    string name,name1,name2,name3,name4;
    cout << "Please enter a name for your players" << endl;
    cin >> name;
    players[0].setName(name);
    players[0].setFullness(50);
    players[0].setLife(true);
    
    cout << "Enter a name for each member of your team" << endl;
    cin >> name1 >> name2 >> name3 >> name4;
    players[1].setName(name1);
    players[1].setFullness(50);
    players[1].setLife(true);
    players[2].setName(name2);
    players[2].setFullness(50);
    players[2].setLife(true);
    players[3].setName(name3);
    players[3].setFullness(50);
    players[3].setLife(true);
    players[4].setName(name4);
    players[4].setFullness(50);
    players[4].setLife(true);
}
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
//returns fullness of a player at a specific index
int Group::getFull(int index)
{
    return players[index].getFullness();
}
/*
Pseudocode for status map
1. This will be displayed every single time they leave a room 
*/
void Group::life(Map &map)
{
    cout << "+-------------+" << endl;
    cout << "|   STATUS    |" << endl;
    cout << "+-------------+" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << map.getRoomCount() << "| Keys: " << keys_ << " | Anger Level: 0" << endl;
    cout << "+-------------+" << endl;    
    cout << "+-------------+" << endl;
    cout << "|    PARTY    |" << endl;
    cout << "+-------------+" << endl;
    cout << "| " << players[0].getName() << " | " << "Fullness: " << players[0].getFullness() << endl;
    cout << "| " << players[1].getName() << " | " << "Fullness: " << players[1].getFullness() << endl;
    cout << "| " << players[2].getName() << " | " << "Fullness: " << players[2].getFullness() << endl;
    cout << "| " << players[3].getName() << " | " << "Fullness: " << players[3].getFullness() << endl;
    cout << "| " << players[4].getName() << " | " << "Fullness: " << players[4].getFullness() << endl;
    cout << "+-------------+" << endl;
}
// Takes a player index and a weapon input and updates the players weapon accordingly
// Adds bonus points if the weapon is the 4th or 5th option from merchant
void Group::setPlayerWeaponAt(int index, int weapon)
{
    if(weapon == 3)
    {
        bonus_++;
    }
    else if(weapon == 4)
    {
        bonus_ = bonus_ + 2;
    }
    else if(weapon == 5)
    {
        bonus_ = bonus_ + 3;
    }
    else
    {
        numWeapons_++;
    }

    

    players[index].setWeapon(weapon);
}
// returns player object at a specified index
Player Group::getPlayerAt(int index)
{
    return players[index];
}
//returns bonus points
int Group::getBonus()
{
    return bonus_;
}
//returns number of weapons
int Group:: getNumWeapons()
{
    return numWeapons_;
}
//incremenets armor
void Group::setArmor2(int x)
{
    armor_ = armor_ + x;
}
//returns armor
int Group::getArmor2()
{
    return armor_;
}
//sets a specif players armor
void Group::setArmorAt(int x)
{
    players[x].setArmor(true);
}
//returns the number of players that are not named "Dead"
int Group::numPlayers()
{
    int counter = 0;
    for(int i = 0; i < 5;  i++)
    {
        if(players[i].getName() != "Dead")
        {
            counter ++;
        }
    }
    return counter;
}
// increments keys
void Group::addKey()
{
    keys_++;
}
// returns number of keys
int Group::getKeys()
{
    return keys_;
}
// uses invest funciton for each player 
// invest function deincrements fullness based on probability when using the investigate action
void Group::groupInvest()
{
    players[0].invest();
    players[1].invest();
    players[2].invest();
    players[3].invest();
    players[4].invest();
}
// uses door function for each player
// door function deincrements fullness based on probability when entering a room 
void Group::groupDoor()
{
    players[0].door();
    players[1].door();
    players[2].door();
    players[3].door();
    players[4].door();
}
// kills a player at specified index
// sets their weapon to a random number so it wont count towards the regular weapons class (makes it extremely unlikely)
void Group::killPlayerAt(int index)
{
    players[index].setName("Dead");
    players[index].setWeapon(rand());
    players[index].setFullness(0);
    players[index].setLife(false);
    players[index].setArmor(false);
}
// adds a fullness point toe each player
// used in cook and eat action menu option 
void Group::groupEat()
{
    players[0].addFullness();
    players[1].addFullness();
    players[2].addFullness();
    players[3].addFullness();
    players[4].addFullness();
}
