// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Class Game
#include <iostream>
#include "Monster.h"
#include <vector>
#include "Map.h"

using namespace std;

class Game
{
private:
    vector<Monster> monsters_;

    int sorcerer_anger_;

    Map map_;

public:

    Game();

    void printMonsters();

    void setSorcerer_anger(int anger);

    int getSorcerer_anger();

    void generateMap();

    Map getMap();

    void setMap(Map map);

};

