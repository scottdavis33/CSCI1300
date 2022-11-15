// CSCI 1300 Fall 2022
// Author: Scott Davis
// Recitation: 308 – Baljot Kaur
// Project 3 - Driver

#include <iostream>
#include <cassert>
#include "Player.h"
#include "Merchant.h"
#include "Monster.h"
#include "Group.h"

using namespace std;

int main()
{
// Asserts for monseters
{
    Monster monster;

    monster.setName("Monster name");
    monster.setLevel(1);
    assert(monster.getName() == "Monster name");
    assert(monster.getLevel() == 1);
}
// Asserts for Player
{
    Player player;

    assert(player.getFullness() == 50);
    assert(player.getName() == "");
    assert(player.getLife() == true);
}
// Asserts for Merhcant
{
    Merchant merchant;

    assert(merchant.getIngredients() == 0);
    merchant.displayMenu();
}

}