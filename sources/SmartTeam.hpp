#pragma once
#include "Team.hpp"
using namespace std;

namespace ariel{
    
class SmartTeam:public Team{
private:
// Two function to help me with the attack function of SmartTeam
// Going to find the victim for the cowboy
size_t FindVictim_Cowboy(Team* EnemyTeam, Point& position) const;
// Going to find the victim for the ninja
size_t FindClosestVictim(Team* EnemyTeam, Point& position) const;

public: // Going to have the constructor , the function attack and the function print

    SmartTeam(Character* Leader);

/*
This function is the principal function of SmartTeam.
We are keeping the same Exception from Team but the way of the attack is different
How is the attack : Cowboys will always attack targets furthest from their Leader's position. 
But if there is a target that has 10 HP it will kill it.
Ninjas will attack the target closest to their position
*/
    void attack(Team* EnemyTeam) override;
    };
}