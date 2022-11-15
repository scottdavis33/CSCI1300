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

