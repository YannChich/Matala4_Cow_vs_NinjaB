#pragma once
#include "Ninja.hpp"

using namespace std;
namespace ariel{

class OldNinja:public Ninja{ // our class YoungNinja implement the class Ninja
public:
// Constructor (using the constructor of Character)
    // Parameterized
    // Using the constructor of Ninja
    // Missing the health and speed because we know their values : speed = 8 / health = 150
    OldNinja(string name,Point location);

    };
}