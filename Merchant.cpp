// CSCI 1300 Fall 2022
// Author: Jared Preyer
// Recitation: 105 - Reagan Rychecky
// Project 3 - Class 1
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
    gold_ = 500;
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
// int Merchant::getCeramicPot()
// {
//     return ceramic_pot_;
// }
int Merchant::getCookware()
{
    // cout <<  "cer pot M" << ceramic_pot_ << endl;
    return ceramic_pot_ + frying_pan_ + cauldron_;
}

int Merchant::getArmor()
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
void Merchant::setArmor()

{
   int choice7= 0;
   int howmany7 = 0;
   char choice3;
    
        cout << "You have entered the armor section. Select the one that applys " << endl;
        cout << "1. Get Armor." << endl;
        cout << "2. Quit Menu." << endl;
        cin >> choice7;
        switch(choice7)
        {
            case 1: 
            {
                cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany7;
                if(howmany7 <= 0)
                {
                    cout << "Invalid input." << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany7 << " suits(s) of armor for 25 Gold? (y/n)" << endl;
                    cin >> choice3;
                    if(choice3 == 'y')
                    {
                        if(howmany7 >= 1)
                        {
                            if(gold_ - (howmany7 * 25) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany7 * 25);
                                armor_ = armor_ + howmany7;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                        
                    }
                    else
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
            default:
            cout << endl;
            cout << "You have quit the menu." << endl;
            break;
        }
   
    
   
   
}
// int Merchant::setCeramicPot(int Ceramic_Pot);
// {
//     ceramic_pot_ = Cerma
// }
/*
Pseudocode Merchant setIngredients
1. Prompt user for how many kg they wish to purchase
2. The ratio is 1 gold/ 1 kg
3. Confirm there purchase
4. prompt User with there remainder goods with their Menu
*/
void Merchant::setIngredients()
{
    int choiceK = 0;
    int howmanyK = 0;
    int kilograms = 0;
    char k;
    
        cout << "You have entered the ingredients. Select 1 or 2. " << endl;
        cout << "1. Get Ingredients." << endl;
        cout << "2. Quit." << endl;
        cin >> choiceK;
        switch(choiceK)
        {
            case 1: 
            {
                cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
                cin >> howmanyK;

                if(howmanyK <= 0 || howmanyK % 5 !=0)
                {
                    cout << "Invalid input." << endl;
                    return;
                }
                else 
                {
                    cout << "You want to buy " << howmanyK << " kg of ingredients for " << howmanyK << " Gold? (y/n)" << endl;
                    cin >> k;

                    if(k == 'y')
                    {
                        if(howmanyK >= 1)
                        {
                            if((gold_ - howmanyK) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else 
                            {
                                gold_ = gold_ - howmanyK;
                                ingredients_ = howmanyK;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                    }
                    else 
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
        }
        
  
    

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
void Merchant::setCookware()
{
    int choice = 0;
    int choice1 = 0;
    char choice2;
    int howmany = 0;

    
        
        
        cout << "I have a several types of cookware, which one would you like? " << endl
             <<  "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                
        cout << "Choose one of the following: " << endl
         << " 1. (25%) Ceramic Pot [2 Gold] " << endl
         << " 2. (10%) Frying Pan [10 Gold] " << endl
         << " 3. ( 2%) Cauldron [20 Gold] " << endl
         << " 4. Cancel " << endl;
        cin >> choice1;
        switch(choice1)
        {
            case 1: 
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany;

                if(howmany <= 0)
                {
                    cout << "Goodbye" << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany << " Cermaic Pot for 2 Gold? (y/n)" << endl;
                    cin >> choice2;

                    if(choice2 == 'y')
                    {
                        if(howmany >= 1 )
                        {
                            // cout << "how many pots we have before" << ceramic_pot_ << endl;
                            
                            // ceramic_pot_ = howmany;
                            if(gold_ - (howmany * 2) < 0)
                            {
                                cout << "You're broke dumby" << endl;
                                
                            }
                            else
                            {
                                gold_ = gold_ - (howmany * 2);
                                ceramic_pot_ = howmany;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                           
                           
                        }
                        // int random1 = rand()%3;
                        // if(random1 == 0)
                        // {
                        //     ceramic_pot_ = "Pot Broken:";
                        //     ceramic_pot_ --; // decrement items that is broken
                        // }
                        // else if(random1 == 1)
                        // {
                        //     ceramic_pot_ = "Cermic Pot is good:";
                        //     ingredients_ = ingredients_ + ceramic_pot_; // Comment need to add ingredients into the pot

                        // }
                        // else if(random1 == 2)
                        // {
                        //     ceramic_pot_ = "Cermic Pot is gucci:";
                        //     ceramic_pot_ = ceramic_pot_ + ingredients_;
                        //     // comment need to add ingredients into the pot
                        // }
                    }
                    else 
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                   
                }
            }
            case 2:
            {
             
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany;

                if(howmany <= 0)
                {
                    cout << "Goodbye" << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany << " Frying Pan for 10 Gold? (y/n)" << endl;
                    cin >> choice2;

                    if(choice2 == 'y')
                    {
                        if(howmany >= 1)
                        {
                            if(gold_ - (howmany * 10) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany * 10);
                                frying_pan_ = howmany;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                      
                        
                    }
                    else 
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                } 

            }
            case 3:
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany;

                if(howmany <= 0)
                {
                    cout << "Goodbye" << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany << " Cauldron(s) for 20 Gold? (y/n)" << endl;
                    cin >> choice2;
                    if(choice2 == 'y')
                    {
                        if(howmany >= 1)
                        {
                            if(gold_ - (howmany * 20) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany * 20);
                                cauldron_ = howmany;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                    }
                    else 
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                   

                }
            }
            default:
            cout << endl;
            cout << "Invalid input. Please select a valid input. " << endl;
            return;
        
        } 
    
    

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
void Merchant::setWeapons()
{
    int choice = 0;
    int howmany1 = 0;
    char setchoice;
    do
    {

        cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl
        << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;

        cout << "Choose one of the following:" << endl
        << "1. Stone Club [2 Gold]" << endl
        << "2. Iron Spear [2 Gold]" << endl
        << "3. (+1) Mythril Rapier [5 Gold]" << endl
        << "4. (+2) Flaming Battle-Axe [15 Gold]" << endl
        << "5. (+3) Vorpal Longsword [50 Gold]" << endl
        << "6. Cancel" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany1;
                if(howmany1 <= 0)
                {
                    cout << "Horrible input. Try again." << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany1 << " Stone Club(s) for 2 Gold? (y/n)" << endl;
                    cin >> setchoice;
                    if(setchoice == 'y')
                    {
                        if(howmany1 >= 1)
                        {
                            if(gold_ - (howmany1 * 2) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany1 * 2);
                                club_ = howmany1;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                            
                        }
                        
                    }
                    else 
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
            case 2:
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany1;
                if(howmany1 <= 0)
                {
                    cout << "Horrible input. Try again." << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany1 << " Iron Spear(s) for 2 Gold? (y/n)" << endl;
                    cin >> setchoice;
                    if(setchoice == 'y')
                    {
                        if(howmany1 >= 1)
                        {
                            if(gold_ - (howmany1 * 2) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany1 * 2);
                                spear_ = howmany1;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                       
                    }
                    else
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
            case 3:
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany1;
                if(howmany1 <= 0)
                {
                    cout << "Horrible input. Try again." << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy "<< howmany1 << " Mythril Rapier(s) for 5 Gold? (y/n)" << endl;
                    cin >> setchoice;
                    if(setchoice == 'y')
                    {
                        if(howmany1 >= 1)
                        {
                            if(gold_ - (howmany1 * 5) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany1 * 5);
                                rapier_ = howmany1;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                        
                    }
                    else
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
            case 4:
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany1;
                if(howmany1 <= 0)
                {
                    cout << "Horrible input. Try again." << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " << howmany1 << " Flaming Battle-Axe(s) for 15 Gold? (y/n)" << endl;
                    cin >> setchoice;
                    if(setchoice == 'y')
                    {
                        if(howmany1 >= 1)
                        {
                            if(gold_ - (howmany1 * 15) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany1 * 15);
                                axe_ = howmany1;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                        
                    }
                    else
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
            case 5:
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> howmany1;
                if(howmany1 <= 0)
                {
                    cout << "Horrible input. Try again." << endl;
                    return;
                }
                else
                {
                    cout << "You want to buy " <<  howmany1 << " Vorpal Longsword(s) for 50 Gold? (y/n)" << endl;
                    cin >> setchoice;
                    if(setchoice == 'y')
                    {
                        if(howmany1 >= 1)
                        {
                            if(gold_ - (howmany1 * 50) < 0)
                            {
                                cout << "Insufficient funds" << endl;
                            }
                            else
                            {
                                gold_ = gold_ - (howmany1 * 50);
                                sword_= howmany1;
                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            }
                            return;
                        }
                        
                    }
                    else
                    {
                        cout << "You have choosen not to proceed with your purchase." << endl;
                        break;
                    }
                }
            }
            default:
            cout << endl;
            cout << "Goodbye Loser!" << endl;
            break;
        
        }   
        
    

    } while (choice != 6);
    
}
void Merchant::setsTreasures()
{
    int select = 0;
    int silver = 0;
    int ruby = 0;
    int emerald = 0;
    int diamond = 0;
    int Gem = 0;

    cout << "Oh so found a treasure that you want to sell back? " << endl;
    cout << "1. To sell Silver ring (R) - 10 gold pieces each" << endl;
    cout << "2. To sell Ruby necklace (N) - 20 gold pieces each" << endl;
    cout << "3. To sell Emerald bracelet (B) - 30 gold pieces each" << endl;
    cout << "4. To sell Diamond circlet (C) - 40 gold pieces each" << endl;
    cout << "5. To sell Gem - encrusted goblet (G) - 50 gold pieces each" << endl;
    cin >> select;

    switch(select)
    {
        case 1: 
        {
            cout << "Congrats on finding a Silver ring. How many would you like to sell? " << endl;
            cin >> silver;
            if(silver <= 0)
            {
                return;
            }
            else if(silver > 1)
            {
                gold_ += silver * 10;
                silver_ = silver_ - silver;
                cout << "Thank you for your transaction. Your deposit has been made. :)" << endl;
                break;
                // Update Merchant inventory for showing that merchant
            }
        }
        case 2:
        {
            cout << "Congrats on finding Ruby. How many would you like to sell? " << endl;
            cin >> ruby;
            if(ruby <= 0)
            {
                return;
            }
            else if(ruby > 1)
            {
                gold_ += ruby * 20;
                ruby_ = ruby_ - ruby;
                cout << "Thank you for your transaction. Your deposit has been made. :)" << endl;
                break;
            }
        }
        case 3:
        {
            cout << "Congrats on finding a Emerald. How many would you like to sell? " << endl;
            cin >> emerald;
            if(emerald <= 0)
            {
                return;
            }
            else if(emerald > 1)
            {
                gold_ += emerald * 30;
                emerald_ = emerald_ - emerald;
                cout << "Thank you for your transaction. Your deposit has been made. :)" << endl;
            }
        }
        case 4:
        {
            cout << "Congrats on finding a Diamond. How many would you like to sell? " << endl;
            cin >> diamond;
            if(diamond <= 0)
            {
                return;
            }
            else if(diamond > 1)
            {
                gold_ += diamond * 40;
                diamond_ = diamond_ - diamond;
                cout << "Thank you for your transaction. Your deposit has been made. :)" << endl;
            }
        }
        case 5:
        {
            cout << "Congrats on finding a Gem. How many would you like to sell? " << endl;
            cin >> Gem;
            if(Gem <= 0)
            {
                return;
            }
            else if(Gem > 1)
            {
                gold_ += Gem * 50;
                gem_ = gem_ - Gem;
                cout << "Thank you for your transaction. Your deposit has been made. :)" << endl;
            }
        }
        default:
        cout << "Goodbye." << endl;
        break;
        
    }
}
/*
Pseudocode Merchant displayMenu
1. This Menu will be the general Menu that every setter User
2. Updates all variables that have been purchased with the correct amount. In each shopping session
3. This Menu will appear until User is done with purhcasing items
*/
void Merchant::displayMenu()
{
    // cout << "ceramic pot" << ceramic_pot_ << endl;
    cout << "Choose one of the following:" << endl
    << "1. Cookware: You will need something to cook those ingredients." << endl
    << "2. Ingredients: To make food, you have to cook raw ingredients." << endl
    << "3. Weapons: It's dangerous to go alone, take this!" << endl
    << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl
    << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl
    << "6. Leave: Make sure you get everything you need. I'm leaving after this sale!" << endl;
    
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
