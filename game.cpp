#include <iostream>
#include <vector>
#include <fstream>
#include "Map.h"
#include "Game.h"
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

{
    ifstream fin;
    fin.open("./riddles.txt");
    string line;
    string answer;
    
    
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            string temp_array[2];
            getline(fin, line);
            split(line, '~', temp_array, 2);
            riddles_.push_back(temp_array[0]);
            answers_.push_back(temp_array[1]);
        }
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

void Game::printRandomRiddle()
{
    int x = rand()%20;

    cout << riddles_.at(x) << endl;

    answer_ = answers_.at(x);

}

void Game::NPCEncounter(Group &G, Map &map)
{
    int choice;

    cout << "You have encountered a dungeon dweller! What would you like to do?" << endl;

    cout << "1. Move" << endl;
    cout << "2. Speak to them" << endl;
    cout << "3. Give up" << endl;
    cin >> choice;

    if(choice == 1)
    {
        char choice1;
        cout << "What direction would you like to move in? (wasd)" << endl;
        cin >> choice1;
        move(choice1, map);
        if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
        {
            NPCEncounter(G, map);
        }
    }
    else if(choice == 2)
    {
        string answer;
        cout << "You must solve a riddle, if it is my wares you seek" << endl;

        cout << endl;

        printRandomRiddle();

        cout << endl;

        cout << "Please enter your answer: " << endl;
        cin >> answer;

        if(answer == answer_)
        {
            char answer;
            cout << "You got the right answer!" << endl;
            cout << "Would you like to buy some items from me? (y/n)" << endl;
            cin >> answer;
            
            int choice20 = 0;
            merchant_.InventoryMenu();
            cin >> choice20;
                switch(choice20)
                {
                    case 1:
                    {
                        merchant_.setCookware();
                        merchant_.displayMenu();
                        break;
                    }
                    case 2:
                    {
                        merchant_.setIngredients();
                        merchant_.displayMenu();
                        break;
                    }
                    case 3:
                    {
                        merchant_.setWeapons(G);
                        merchant_.displayMenu();
                        break;
                    }
                    case 4:
                    {
                        merchant_.setArmor(G);
                        merchant_.displayMenu();
                        break;
                    }
                    case 5:
                    {
                        merchant_.setsTreasures();
                        merchant_.displayMenu();
                        break;
                    }
                    default:
                    cout << "Enjoy your journey team!" << endl;
                    break;
                }
        }
        else 
        {
            monsterFight(G);    
        }
    }
}


void Game::move(char c, Map &m)
{
    if(c == 'w' || c == 'a' || c == 's' || c == 'd')
    {
        group_.groupmove();
        m.move(c);

        m.displayMap();
    } 
    else
    {
    cout << "Invalid input" << endl;
    }
}


// Monster Game::getRandomMonster()
// {
//     // int x = rand()%4;

//     // monsterIndex_ = x;

//     // return monsters_.at(x);
// }

void Game::investigate(Group &G)
{
    
    if(rand()%2 == 1)
    {
        G.groupInvest();
    }
    if(rand()%5 == 2)
    {
        cout << "You found hidden treasure!" << endl;
        // if(roomsCleared_ = 1)
        merchant_.addSilver();
        cout << "+1 silver" << endl;
    }
    if(rand()%10 == 5)
    {
        cout << "You found a key!" << endl;
        G.addKey();
    }
    if(rand()%100 >= 1 || rand()%100 < 40)
    {
        cout << "Misfortune" << endl;
    }
}

string Game::getMonsterName()
{
    
    int x = rand() % 4;
    string name = monsters_.at(x).getName();
    monsters_.erase(monsters_.begin()+x);
    return name;
}


void Game::monsterFight(Group &G)
{
    int choice;
    int d = 0;
    string y = getMonsterName();
    cout << y << " AHEAD! THEY LOOK HOSTILE!" << endl;

    // If the number of weapons in inventory is greater than 1
    if(G.getNumWeapons() == 0)
    {
        cout << "Sorry, you need at least one weapon to pick a fight with a monster" << endl;

        return;
    }

    cout << "1. Fight" << endl;
    cout << "2. Surrender" << endl;
    cin >> choice;

    // calculations for variable d
    if
    (
    G.getPlayerAt(0).getWeapon() != G.getPlayerAt(1).getWeapon() &&
    G.getPlayerAt(1).getWeapon() != G.getPlayerAt(2).getWeapon() &&
    G.getPlayerAt(2).getWeapon() != G.getPlayerAt(3).getWeapon() &&
    G.getPlayerAt(3).getWeapon() != G.getPlayerAt(4).getWeapon() 
    ) 
    {
        d = 4;
    }
    //Calculations for variable w
    int w = G.getNumWeapons() + G.getBonus(); 
    //Calculations for variable a
    int a = G.getArmor2();
    //Calculation for variable C
    int c = 1; // for now (Based on rooms cleared)
    //Calculation for variables r
    int r1 = rand()%6 + 1;
    int r2 = rand()%6 + 1;

    if(choice == 1)
    {

       
        if
        (((r1 * w + d) - ((r2*c)/(c))) > 0)
        {
            cout << "You have won the battle!" << endl;
            cout << "You've earned " << 10*c << " gold!" << endl;
            cout << "You've earned " << 5*c << " ingredients!" << endl;
            merchant_.addGold(10*c);
            merchant_.addIngrediants(5 * c);
            if(rand()%10 == 2)
            {
                cout << "The monster was hiding a key!" << endl;
                G.addKey();
            }
            
        }
        else
        {
            int j = rand()%5;
            cout << "You have lost the battle" << endl;

            merchant_.subGold(merchant_.getGold() / 4);

            cout << "The monster took " << (merchant_.getGold() /4) << " gold from the group!" << endl;

            for(int i = 0; i < G.numPlayers(); i++)
            {
                if(G.getPlayerAt(i).checkArmor() == false)
                {
                    if(rand() % 10 == 3)
                    {
                        cout << "You'll forever be scarred from watching the monster dismember " << G.getPlayerAt(i).getName() << " limb for limb." << endl;
                        G.killPlayerAt(i);
                    }
                }
                else if (G.getPlayerAt(i).checkArmor() == true)
                {
                    if(rand() % 20 == 4)
                    {
                        cout << "In order to save yourself, you pushed " << G.getPlayerAt(i).getName() << " out of your way, the monster laughed as you watched them devour your old friend" << endl;
                        G.killPlayerAt(i);
                    }
                }
            }
 
            for(int i = 0; i < G.numPlayers(); i++)
            {
                if(rand()%2 == 1);
                G.getPlayerAt(i).setFullness(G.getPlayerAt(i).getFullness() - 1);
            }

            if(j == 0)
            {
                merchant_.addIngrediants(-5);
                cout << "You lost 5 kg of ingredients" << endl;
            }
            else if( j == 0)
            {
                merchant_.addIngrediants(-10);
                cout << "You lost 10 kg of ingredients" << endl;
            }
            else if(j == 1)
            {
                merchant_.addIngrediants(-15);
                cout << "You lost 15 kg of ingredients" << endl;
            }
            else if(j == 2)
            {
                merchant_.addIngrediants(-20);
                cout << "You lost 20 kg of ingredients" << endl;
            }
            else if(j == 3)
            {
                merchant_.addIngrediants(-25);
                cout << "You have lost 25 kg of ingredients" << endl;
            }
            else if (j ==4)
            {
                merchant_.addIngrediants(-30);
                cout << "You have lost 30 kg of ingredients" << endl;
            }

        }
    }
    else if(choice == 2)
    {
        cout << "You lost the battle" << endl; // one random player is captured
        int a = rand()%4 + 1;
        cout << G.getPlayerAt(a).getName() << " called the monster a homophobic slur, resulting in him getting his face repeatedly bashed against the dungeon wall" << endl;
        G.killPlayerAt(a);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}
void Game::CookandEat()
{
        // Needs to add the cookware increase in fullness if completed successfully
        int Ceramic = 0; // This function only
        int Frying = 0;
        int Cauldron = 0;
        int cook = 0;
        // cook and eat
        cout << "The cooking ratio is set at a 5(kg):1(ingredient)." << endl;
        cout << "Which cookware item would you like to use ? " << endl;
        cout << "1. Ceramic Pot. " << endl;
        cout << "2. Frying Pan. " << endl;
        cout << "3. Cauldron " << endl;
        cout << "4. Quit." << endl;
        cin >> cook;
        switch(cook)
        {
            case 1:
            {
                cout << "How many of kilograms of ingredients would you like to use with a 5(kg):1(ingredient) ratio ? " << endl;
                cin >> Ceramic;
                
                // Need to add the 5:1 Ratio check
                if(Ceramic%5 == 0)
                {
                    // int random1 = rand()%4;
                    int random1 = rand()%4;
                    if(random1 == 0)
                    {
                        merchant_.breakCeramic(Ceramic);
                    }

                }
                else
                {
                    
                    // Needs to add the cookware increase in fullness if completed successfully
                    return;
                }
                break;
               

            }
            case 2:
            {
                cout << "How many of kilograms of ingredients would you like to use with a 5(kg):1(ingredient) ratio ? " << endl;
                cin >> Frying;

                // Need to add the 5:1 Ratio check with fullness
                if(Frying%5 == 0)
                {
                    int random2 = rand()%10;
                    if(random2 == 0)
                    {
                        merchant_.breakFrying(Frying);
                    }
                }
                else 
                {
                    return;
                }
                
            }
            case 3:
            {
                cout << "How many of kilograms of ingredients would you like to use with a 5(kg):1(ingredient) ratio ? " << endl;
                cin >> Cauldron;
                
                
                if(Cauldron%5 == 0)
                {
                    int random3 = rand()%50;
                    if(random3 == 0)
                    {
                        merchant_.breakCauldron(Cauldron);
                    }
                }
                else
                {
                    return;
                }
            }
            default:
            cout << "Incorrect Input. " << endl;
            return;
        }
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
}

