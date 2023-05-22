#pragma once
#include "Ninja.hpp"

using namespace std;
namespace ariel{

class TrainedNinja:public Ninja{ // our class YoungNinja implement the class Ninja
public:
// Constructor (using the constructor of Character)
    // Parameterized
    // Using the constructor of Ninja
    // Missing the health and speed because we know their values : speed = 12 / health = 120
    TrainedNinja(string name,Point location);

    };
}