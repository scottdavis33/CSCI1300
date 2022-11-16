#include <iostream>
#include <vector>
#include <fstream>
#include "Map.h"
#include "game.h"
#include "Monster.h"
#include "Player.h"
#include "Group.h"
#include "Merchant.h"

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
{
    //initilize variable for number of pieces the string is split into
    int ind = 0;
    //if string is blank return 0
    if (input_string == "")
    {
        return 0;
    }
    
        //for loop that goes through the entire input string
    for(int i =0; i < input_string.length(); i++)
    {
        // when we dont find the seperator 
        if(input_string[i] != separator) 
        {
            if(ind >= arr_size) // in case the ind gets too big
            {
                return -1;
            }
            arr[ind] += input_string[i];
        }
        else // if we find the seperator add one to the index 
        {
            ind++;
        }
    }
    return ind + 1; // if index = 0 (never run into the seperator it'll return 1)
    
}

Game::Game()
{
//Fills a vector with all of the monsters
{
    ifstream fin;
    fin.open("./monster.txt");
    string line;
    Monster monster;
    
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            getline(fin, line);
            string temp_array[2];
            int j = split(line, ',', temp_array, 2);
            if(j == 2)
            {
                monster = Monster(temp_array[0], stoi(temp_array[1]));
                
                monsters_.push_back(monster);
            }
        }
    }    
}

// Defaults the sorcerer
{
    sorcerer_anger_ = 0;
}
// adds 5 rooms and 5 NPCs somwhere on the map
{
    srand(time(NULL));

    for(int i = 0; i < 5; i++)
    {
        map_.addNPC(rand()%12, rand()%12);
        map_.addRoom(rand()%12, rand()%12);
        NPCCount_++;
    }
}
}
int Game::NPCCount()
{
    return NPCCount_;
}
void Game::printMonsters()
{
    for(int i = 0; i < 21; i++)
    {
        cout << monsters_.at(i).getName() << endl;
        cout << monsters_.at(i).getLevel() << endl;
    }
}

void Game::setSorcerer_anger(int anger)
{
    sorcerer_anger_ = anger;
}

int Game::getSorcerer_anger()
{
    return sorcerer_anger_;
}


Map Game::getMap()
{
    return map_;
}


void Game::move(char c, Map m)
{
    if(c == 'w' || c == 'a' || c == 's' || c == 'd')
    {
        group_.groupmove();
        m.move(c);
    } 
    else
    {
    cout << "Invalid input" << endl;
    }
}

void Game::investigate()
{
    if(rand()%2 == 1)
    {
        player_.setFullness(player_.getFullness() - 1);
    }
    if(rand()%5 == 2)
    {
        cout << "You found hidden treasure!" << endl;
    }
    if(rand()%5 == 2)
    {
        cout << "Uh oh! You've encountered a monster!" << endl;
    }
    if(rand()%10 == 5)
    {
        cout << "You found a key!" << endl;
    }
    if(rand()%100 >= 1 || rand()%100 < 40)
    {
        cout << "Misfortune" << endl;
    }
}

void Game::monsterFight()
{

}

void Game::printActionMenu()
{
    int choice;
    // do{
    cout << "Please select an action: " << endl;
    cout << endl;
    cout << "1. Move" << endl;
    cout << "2. Investigate" << endl;
    cout << "3. Pick a Fight" << endl;
    cout << "4. Cook and Eat" << endl;
    cout << "5. Give up" << endl;
    cin >> choice;

    if(choice <=0 || choice > 5)
    {
        cout << "Invalid input, please select a different action" << endl;
    }

    if(choice == 1)
    {
        char choice1;
        cout << "What direction would you like to move in? (wasd)" << endl;
        cin >> choice1;
        move(choice1, getMap());
    }
    else if(choice == 2)
    {
        if(map_.isExplored(map_.getPlayerRow(), map_.getPlayerCol()) == true)
        {
            cout << "This space can not be investigated again, please pick another option" << endl;
        }
        else
        {
            investigate();
        }
    }
    else if(choice == 3)
    {
        // Random monster appears
    }
    else if(choice == 4)
    {
        int Ceramic = 0;
        int Frying = 0;
        int Cauldron = 0;
        int cook = 0;
        // cook and eat
        cout << "The cooking ratio is set at a 5(kg):1(ingredient)." << endl;
        cout << "Which cookware item would you like to use ? " << endl;
        cout << "1. Ceramic Pot. " << endl;
        cout << "2. Frying Pan. " << endl;
        cout << "3. Cauldron " << endl;
        cin >> cook;
        switch(cook)
        {
            case 1:
            {
                cout << "How many of kilograms of ingredients would you like to use with a 5(kg):1(ingredient) ratio ? " << endl;
                cin >> Ceramic;
                
                // Need to add the 5:1 Ratio check
                int random1 = rand()%4;
                if(random1 == 0)
                {
                    merchant_.breakCookware();
                }

            }
            case 2:
            {
                cout << "How many of kilograms of ingredients would you like to use with a 5(kg):1(ingredient) ratio ? " << endl;
                cin >> Frying;

                // Need to add the 5:1 Ratio check
                
                
            }
            case 3:
            {
                cout << "How many of kilograms of ingredients would you like to use with a 5(kg):1(ingredient) ratio ? " << endl;
                cin >> Cauldron;
                
                int random3 = rand()%50;

                if(random == 0)
                {
                    merchant_.breakCookware();
                }
            }
            default:
            cout << "Incorrect Input. " << endl;
            return;
        }
        
    }
    else if(choice ==5)
    {
        cout << "You are a pussy" << endl;
    }

    // }while(choice != 5);
}




