// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Class Game
#include <iostream>
#include <vector>
#include <fstream>
#include "Game.h"
#include "Map.h"

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


// void Game::setMap(Map map)
// {
//     cout << "Jared is daddy" << endl;
//     map_ = map;

// }

void Game::generateMap()
{
    
    for(int i = 0; i < 5; i++)
    {
        map_.addNPC(rand()%12, rand()%12);
        map_.addRoom(rand()%12, rand()%12);
    }

}

Map Game::getMap()
{
    return map_;
}


