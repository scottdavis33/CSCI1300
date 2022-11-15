#include <iostream>
#include "Game.h"
#include "Monster.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    Game game = Game();

    game.getMonsters();
    
    return 0;
}