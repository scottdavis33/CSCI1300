// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Dungeon Game
#include <iostream>
#include "Group.h"
#include "Map.h"
#include "Merchant.h"
#include "Player.h"

int main()
{
    char Inven;
    int options = 0;
    Group G;
    G.setFullandName();
    Merchant M;
    
    do
    {
        
        M.displayMenu();
        cin >>options;
        /* 
        1. This is keeping the inventory for the whole group.
        2. Gold is set at 500
        3. This do while will prompt the whole group until the the run out of resources
        */
        switch(options)
        {
            case 1:
            {
                M.setCookware();
                break;
            }
            case 2:
            {
                M.setIngredients();
                break;
            }
            case 3:
            {
                M.setWeapons();
                break;
            }
            case 4:
            {
                M.setArmor();
                break;
            }
            case 5:
            {
                M.setsTreasures();
            }
            default:
            cout << "Enjoy your journey team!" << endl;
            break;
        }

    } while (options != 6);
    
}
