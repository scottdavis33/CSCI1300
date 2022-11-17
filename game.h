// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Dungeon Game
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Monster.h"
#include <vector>
#include "Map.h"
#include "Group.h"
#include "Player.h"
#include "Merchant.h"
#include "Player.h"


using namespace std;






class Game
{
private:
    vector<Monster> monsters_;

    int sorcerer_anger_;

    Map map_;

    int NPCCount_;

    void MapMove();

    Group group_;

    Player player_;

    vector<string> riddles_;

    vector<string> answers_;

    string answer_;

public:

    Game();

    void printMonsters();

    void setSorcerer_anger(int anger);

    int getSorcerer_anger();

    void generateMap();

    Map getMap();

    void setMap(Map map);

    int NPCCount();

    void move(char, Map& );

    void printActionMenu();

    void investigate();

    void monsterFight();

    void NPCEncounter(Map&);

    void printRandomRiddle();

    void CookandEat();
    Merchant merchant_;


};

#endif


