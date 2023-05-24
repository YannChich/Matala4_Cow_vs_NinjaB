#pragma once
#include "Team.hpp"
using namespace std;

namespace ariel{
    
class SmartTeam:public Team{
public: // Going to have the constructor , the function attack and the function print

    SmartTeam(Character* Leader);

/*
This function is the principal function of SmartTeam.
We are keeping the same Exception from Team but the way of the attack is different
How is the attack : You will see in the PartB
*/
    void attack(Team* EnemyTeam) override;
    };
}