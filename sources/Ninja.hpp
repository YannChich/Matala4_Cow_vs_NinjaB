#pragma once
#include "Character.hpp"

using namespace std;
namespace ariel{

class Ninja:public Character{ // our class Ninja implement the class Character
private:
// Data of a Ninja
    int Speed;

public:
// Constructor (using the constructor of Character)
    // Parameterized
    // Adding health and speed because we got 3 differents type of Ninja
    Ninja(string name,Point location,int health,int speed);

// Function for a Ninja
/*
-This function move on our game the ninja to the enemy.(use the function moveToward of Class::Point)
*/
    void move(Character* enemy);

/*
-This function going to represent the action of the Ninja : slash someone
-Exception : if the enemy is not a meter away , there is no damage
-Damage of slash : -40HP
*/
    void slash(Character* enemy);
/*
-This function is the override of the virtual function of the Character
-The function print the detail of a Character and add C before the Print
*/
    string print()const override;

// Getter for the private data
    int getSpeed() const;
    };
}