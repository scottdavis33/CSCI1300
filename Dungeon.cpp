// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Dungeon Game
#include <iostream>
#include "Group.h"
#include "Map.h"
#include "Merchant.h"
#include "Player.h"
#include "game.h"

using namespace std;


int main()
{
    Game Eat;
    Map Status;
    Map  map = Eat.getMap();
    int randMisfortune;
    char Inven;
    int options = 0;
    Group G;
    G.setFullandName();
    Merchant M;
    
    int ActionMenu = 0;
    
    do
    {
        M.InventoryMenu();
        cin >> options;
        Eat.merchant_.displayMenu();
        
        /* 
        1. This is keeping the inventory for the whole group.
        2. Gold is set at 500
        3. This do while will prompt the whole group until the the run out of resources
        */
        switch(options)
        {
            case 1:
            {
                Eat.merchant_.setCookware();
                Eat.merchant_.displayMenu();
                break;
            }
            case 2:
            {
                Eat.merchant_.setIngredients();
                Eat.merchant_.displayMenu();
                break;
            }
            case 3:
            {
                Eat.merchant_.setWeapons(G);
                Eat.merchant_.displayMenu();
                break;
            }
            case 4:
            {
                Eat.merchant_.setArmor(G);
                Eat.merchant_.displayMenu();
                break;
            }
            case 5:
            {
                Eat.merchant_.setsTreasures();
                Eat.merchant_.displayMenu();
                break;
            }
            default:
            cout << "Enjoy your journey team!" << endl;
            Eat.merchant_.displayMenu();
            break;
        }

    } while (options != 6);
    G.life(Status);
    Eat.merchant_.displayMenu(); // Eat.merchant_.displayMenu() Updating correct numbers
    // Eat.merchant_.printActionMenu();
    do
    {
        Eat.printActionMenu();
        cin >> ActionMenu;

        switch(ActionMenu)
        {
            case 1:
            {
                char choice1;
                cout << "What direction would you like to move in? (wasd)" << endl;
                cin >> choice1;
                Eat.move(choice1, map);
            if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
            {
                Eat.NPCEncounter(G, map);
            }
            if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
            {
                G.groupDoor();

                if(G.getKeys() <= 0)
                {
                    Eat.doorPuzzle(G, map);
                }
                else
                {
                    cout << "You enter the room, it smells funny..." << endl;
                    Eat.monsterFight(G, map);
                }
            }

                break;
            }
            case 2:
            {
                if(map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    cout << "This space can not be investigated again, please pick another option" << endl;
                }
                else
                {
                    if(rand()%5 == 2)
                    {
                        Eat.monsterFight(G, map);
                        break;
                    }
                    Eat.investigate(G);
                    Eat.merchant_.displayMenu();
                }
                G.life(map);
                break;
            }
            case 3:
            {
                Eat.monsterFight(G, map);
                Eat.merchant_.displayMenu();
                G.life(map);

                break;
            }
            case 4:
            {
                Eat.CookandEat(G);
                Eat.merchant_.displayMenu();
                G.life(map);


                break;
            }
            default:
            cout << "You have choosen to end the game." << endl;
            break;
        }
        if(Eat.getDoorsCleared() == 5)
        {
            cout << "You have cleared all 5 rooms. You win!" << endl;
        }

    } while (ActionMenu != 5);
    
};


