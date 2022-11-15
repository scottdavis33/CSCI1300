// CSCI 1300 Fall 2022
// Author: Scott Davis
// Recitation: 308 – Baljot Kaur
// Project 3 - Class 2
#include <iostream>
#include <cstdlib>
#include "Merchant.h"
using namespace std;
/*
Pseudocode Merchant Menu default constructor
1. Make all variables set to zero
2. Except the gold at 100 and 
*/
Merchant::Merchant()
{
    club_ = 0;
    spear_ = 0;
    rapier_ = 0;
    axe_ = 0;
    sword_ = 0;
    ingredients_ = 0;
    ceramic_pot_ = 0;
    frying_pan_ = 0;
    cauldron_ = 0;
    armor_ = 0;
    silver_ = 0;
    ruby_ = 0;
    emerald_ = 0;
    diamond_ = 0;
    gem_ = 0;
    gold_ = 100;
}
/*
Pseudocode Merchant getters
1. return the variables in the default contructor that are applicable
*/
int Merchant::getIngredients()
{
    return ingredients_;
}

int Merchant::getWeapons()
{
    return club_ + spear_ + rapier_ + axe_ + sword_;
}

int Merchant::getCookware()
{
    return ceramic_pot_ + frying_pan_ + cauldron_;
}

bool Merchant::getArmor()
{
    return armor_;
}

int Merchant::getTreasures()
{
    return silver_ + ruby_ + emerald_ + diamond_ + gem_;
}
/*
Pseudocode Merchant setArmor
1. Make armor set to 0
2. prompt user for if they would purchace any
3. confirm purchase.
4. Each armor is worth 5 gold points
5. Subtract each armor that they get from their total amount of gold
6. After all reprompt user to the Inventory Menu that shows them how many goods they have
*/
void Merchant::setArmor(bool armor)
{
   
}
/*
Pseudocode Merchant setIngredients
1. Prompt user for how many kg they wish to purchase
2. The ratio is 1 gold/ 1 kg
3. Confirm there purchase
4. prompt User with there remainder goods with their Menu
*/
void Merchant::setIngredients(int ingredients)
{
    int kilograms = 0;

    cout << "how many kilograms of ingredients they wish to purchase?" << endl;
    cin >> kilograms;

    if(kilograms > 0)
    {
        ingredients_ = kilograms + ingredients_; // the total ingredients is dependend on the kilograms the user wants w adde
        
        gold_ = gold_ - kilograms;  
    }
    // Might want this function to be in mergent
}
/*
Pseudocode Merchant getCookware
1. Prompt user for which Pot they want
2. Declare variables for the do while loop
3. Use conditions for all 4 options
4. Use the random number generator. (Each pot has a probability of breaking. If remainder == 0 they have broke their pot)
5. If player tries to buy more then the actual gold they have prompt user with error message
6. After payments have been confirmed. Reprompt menu with updated purchases

*/
void Merchant::setCookware(int ceramic_pot, int frying_pan, int cauldron)
{
    // int choice = 0;
    // int choice1 = 0;
    // string choice2;

  
    //        do
    //         {
    //             cout << "I have a several types of cookware, which one would you like? " << endl
    //                 <<  "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                
    //             cout << "Choose one of the following: " << endl
    //                  << " 1. (25%) Ceramic Pot [2 Gold] " << endl
    //                  << " 2. (10%) Frying Pan [10 Gold] " << endl
    //                  << " 3. ( 2%) Cauldron [20 Gold] " << endl
    //                  << " 4. Cancel " << endl;
    //                  cin >> choice1;
    //             if(choice1 == 1)
    //             {   
    //                 cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
    //                 cin >> gold_;

    //                 if(gold_ <= 0)
    //                 {
    //                     cout << "Goodbye." << endl;
    //                 }
    //                     else if(gold_ <= 1)
    //                     {
    //                         cout << "You want to buy " gold_  " Cermaic Pot for 2 Gold? (y/n)" << endl;
    //                         cin >> choice2;

    //                         if(choice2 == 'y')
    //                         {
    //                             if(gold_ > 0)
    //                             {
    //                                 gold_ = gold_ - 2; 
    //                             }
                            
    //                             int random1 = rand() % 3;
    //                             if(random1 == 0)
    //                             {
    //                                 ceramic_pot_ = "Pot Broken:";
    //                                 ceramic_pot_ --; // decrement items that is broken
    //                             }
    //                             else if(random1 == 1)
    //                             {
    //                                 ceramic_pot_ = "Cermic Pot is good:";
    //                                 ingredients_ = ingredients_ + ceramic_pot_; // Comment need to add ingredients into the pot

    //                             }
    //                             else if(random1 == 2)
    //                             {
    //                                 ceramic_pot_ = "Cermic Pot is gucci:";
    //                                 ceramic_pot_ = ceramic_pot_ + ingredients_;
    //                                 // comment need to add ingredients into the pot
    //                             }
    //                         }
    //                         else
    //                         {
    //                             break;
    //                         }
    //                     }

    //             else if(choice1 == 2)
    //             {
                        
    //                 cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
    //                 cin >> gold_;

    //                 if(gold_ <= 0)
    //                 {
    //                 cout << "Goodbye." << endl;
    //                 break; // Just an idea
    //                 }
    //                 else if(gold_ > 1)
    //                 {
    //                     cout << "You want to buy " gold_  " Frying Pan for 10 Gold? (y/n)" << endl;
    //                     cin >> choice2;

    //                     if(choice == 'y')
    //                     {
    //                     if(gold_ > 0)
    //                     {
    //                         gold_ = gold_ - 10;
    //                     }
    //                         int random2 = rand() % 9;
    //                         if(random2 == 0)
    //                         {
    //                             frying_pan_ = "Pot Broken";
    //                             frying_pan_ --;
    //                         }
    //                         // Ask about the other 9 conditions 
    //                         cout << "Thank you for your patronage! What else can I get for you?" << endl;
    //                     }
    //                     else 
    //                     {

    //                         break;
    //                     }
    //                 }    

    //             }
    //             else if(choice1 == 3)
    //             {
    //                 cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
    //                 cin >> gold_;

    //                 if(gold_ <= 0)
    //                 {
    //                     cout << "Goodbye." << endl;
                        
    //                 }
    //                 else if(gold_ > 1)
    //                 {
    //                     cout << "You want to buy " gold_ << " Cauldron(s) for 20 Gold? (y/n)" << endl;
    //                     cin >> choice2;

    //                     if(choice2 == 'y')
    //                     {
                            
    //                     }
    //                 }
    //             }
    //             else if()
    //             {

    //             }
    //             else
    //             {
    //                 cout << "Goodbye" << endl;
    //             }
    //             } while (choice1 != 4);

    //         }

}
/*
Pseudocode Merchant setWeapons
1. Declare all variables
2. Prompt User with Menu needed
3. Prompt User with which item they would like to purchase
4. set up a do while which with conditions
5. Subtract how many every gold then want from there purchase
6. Reprompt them with the same options until gold is not suffient || they want to exit Menu

*/
void Merchant::setWeapons(int club, int spear, int rapier, int axe, int sword)
{
    gold_ = gold_ - 2;
    club_ = 2 * gold_;
    spear_ = 2 * gold_;
    rapier_ = 5 * gold_;
    axe_ = 15 * gold_;
    sword_ = 50 * gold_;
    weapons_ = club_ + spear_ + rapier_ + axe_ + sword_;

    int choice = 0;
    int choice1 = 0;
    string choice2;
    do
    {   
        

        if(choice == 1)
        {   
            
        }
        else if(choice == 2)
        {

        }
        else if(choice == 3)
        {

        }
        else if(choice == 4)
        {

        }
        else if(choice == 5)
        {

        }
        else if(choice == 6)
        {

        }
    } while (choice != 6);
    
}
/*
Pseudocode Merchant displayMenu
1. This Menu will be the general Menu that every setter User
2. Updates all variables that have been purchased with the correct amount. In each shopping session
3. This Menu will appear until User is done with purhcasing items
*/
void::Merchant::displayMenu()
{
    cout << "+-------------+" << endl
    << "| INVENTORY   |" << endl
    << "+-------------+" << endl
    << "| Gold        | " << gold_ << endl
    << "| Ingredients | " << ingredients_ << " kg" << endl
    << "| Cookware    | P: " << ceramic_pot_ << " |  F: " << frying_pan_ << "| C: " << cauldron_ << endl
    << "| Weapons     | C: " << club_ << " | S: " << spear_ << " | R: " << rapier_ << " | A: " << axe_ << " | SW: " << sword_ << endl
    << "| Armor       | " << armor_ << endl
    << "| Treasures   | S: " << silver_ << " | R: " << ruby_ << " | E: " << emerald_ << " | D: " << diamond_ << " | G: " << gem_ << endl;

}
