#pragma once
#include "Character.hpp"

using namespace std;
namespace ariel{

class Cowboy:public Character{ // our class Cowboy implement the class Character 
private :
// Data for a Cowboy
    int bullets; // Limited to 6 bullets

public :
// Constructor (using the constructor of Character)
    // Parameterized
    // Missing health and bullets because we know their value healt = 110 / bullet = 6
    Cowboy(string name,Point location);

// Function for a Cowboy
/*
-This function going to represent the action of the Cowboy : shooting to someone
-Exception : if the cowboy is dead or the cowboy don't have bullet
-Damage of shoot : -10 HP
-The Cowboy lost one bullet
*/
    void shoot(Character* enemy);

/*
-This function return True if the cowboy have bullets else False
*/
    bool hasboolets() const;

/*
-This function going to reload the gun of the cowboy
-Exception : if the cowboy got already 6 bullets
-If the Cowboy got between 1 and 5 bullets we need to add only 6 - this.number 
*/
    void reload();

/*
-This function is the override of the virtual function of the Character
-The function print the detail of a Character and add C before the Print
*/
     string print()const override;
    };
}