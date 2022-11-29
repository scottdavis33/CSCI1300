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

int main()
{
    Game Eat;
    Map Status;
    Map  map = Eat.getMap();
    char Inven;
    int options = 0;
    Group G;
    G.setFullandName();
    Merchant M;
    
    int ActionMenu = 0;
    
    do
    {
        cout << "Choose one of the following:" << endl
        << "1. Cookware: You will need something to cook those ingredients." << endl
        << "2. Ingredients: To make food, you have to cook raw ingredients." << endl
        << "3. Weapons: It's dangerous to go alone, take this!" << endl
        << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl
        << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl
        << "6. Leave: Make sure you get everything you need. I'm leaving after this sale!" << endl;
        cin >>options;
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
                break;
            }
            case 2:
            {
                Eat.merchant_.setIngredients();
                break;
            }
            case 3:
            {
                Eat.merchant_.setWeapons(G);
                break;
            }
            case 4:
            {
                Eat.merchant_.setArmor(G);
                break;
            }
            case 5:
            {
                Eat.merchant_.setsTreasures();
            }
            default:
            cout << "Enjoy your journey team!" << endl;
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
                        Eat.monsterFight(G);
                        break;
                    }
                    Eat.investigate();
                }
                break;
            }
            case 3:
            {
                Eat.monsterFight(G);
                break;
            }
            case 4:
            {
                Eat.CookandEat();
                Eat.merchant_.displayMenu();

                // cout << "Players weapons: " << endl;
                // cout << "Player 1: " << G.getPlayerAt(0).getWeapon() << endl;
                // cout << "Player 2: " << G.getPlayerAt(1).getWeapon() << endl;
                // cout << "Player 3: " << G.getPlayerAt(2).getWeapon() << endl;
                // cout << "Player 4: " << G.getPlayerAt(3).getWeapon() << endl;
                // cout << "Player 5: " << G.getPlayerAt(4).getWeapon() << endl;

                break;
            }
            default:
            cout << "You have choosen to end the game." << endl;
            break;
        }
    } while (ActionMenu != 5);
    
    // Eat.CookandEat();
    // Eat.merchant_.displayMenu(); // Updating correct numbers
}
