#pragma once
#include "Team.hpp"

using namespace std;

namespace ariel{

class Team2:public Team{
public: // Going to have the constructor , the function attack and the function print

    Team2(Character* Leader);

/*
This function is the principal function of Team2.
We are keeping the same Exception from Team but the way of the attack is different
How is the attack : The order is base on the entry of the Character and not Type.
*/
    void attack(Team* EnemyTeam) override;

   };
}