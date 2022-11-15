#include <iostream>
#include "Monster.h"
#include <vector>

using namespace std;

class Game
{
private:
    vector<Monster> monsters_;
    int sorcerer_anger_;

public:

    Game();

    void getMonsters();

    void setSorcerer_anger(int anger);

    int getSorcerer_anger();

};