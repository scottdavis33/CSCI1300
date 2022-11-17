// CSCI 1300 Fall 2022
// Author: Jared Preyer && Scott Davis 
// Recitation: 105 - Reagan Rychecky && 308 - Baljot Kaur
// Project 3 - Class Merchant
#include <iostream>
#ifndef Merchant_H
#define Merchant_H
using namespace std;

/*
Pseudocode Merchant Menu
1. Make all public functions and private members
2. Each setter has its own parameters as shown in the right up
3. This menu is only applicable if players want to take advantage before there journey
*/

class Merchant
{
    public:
        Merchant(); // default constructor
        
        int getIngredients();
        int getWeapons();
        int getCookware();
        int getArmor();
        int getTreasures();
        // int getCeramicPot();
        // int getCeram
        void setName();
        void setIngredients();
        void setWeapons();
        void setCookware();
        void setArmor();
        void setsTreasures();
        // int setCeramicPot(int Ceramic_Pot);
        void displayMenu();
        void breakCeramic(int Ceramic); 
        void breakFrying(int Fry);
        void breakCauldron(int Cauld);
        
        


    private:
        int club_;
        int spear_;
        int rapier_;
        int axe_;
        int sword_;
        int ingredients_;
        int ceramic_pot_;
        int frying_pan_;
        int cauldron_;
        int armor_;
        int silver_;
        int ruby_;
        int emerald_;
        int diamond_;
        int gem_;
        int gold_;
        int weapons_;
        

};
#endif



