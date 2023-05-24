#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character *Leader) : Team(Leader) {}

/*
This function is the principal function of Team2.
We are keeping the same Exception from Team but the way of the attack is different
How is the attack : The order is base on the entry of the Character and not Type.
*/
void Team2::attack(Team *EnemyTeam)
{
    // if the EnemyTeam is null we need to throw a invalid argument
    if (EnemyTeam == nullptr)
    {
        throw invalid_argument("The EnemyTeam is a null ptr");
    }
    // If the EnemyTeam is dead throw a error
    if (EnemyTeam->stillAlive() == 0)
    {
        throw runtime_error("The enemy Team is dead");
    }
    // We need to check if the Leader is alive or not
    if (this->getLeader()->isAlive() == false)
    {
        // finding the index of the Leader
        size_t i_leader = FindLeader();
        // updating the new Leader
        this->setLeader(this->getVector()[i_leader]);
    }
    // We need now to find the enemy character closest to the Leader
    size_t i_enemy = FindVictim(EnemyTeam);
    Character *Victim = EnemyTeam->getVector()[i_enemy];
    // Now every Character of the atack's Team2 going to atack the enemy
    // We are just running into the vector and atack
    for (Character *character : this->getVector())
    {
        // Every run on the next cowboy we need to check if the victim is alive or not
        if (Victim->isAlive() == false)
        {
            i_enemy = FindVictim(EnemyTeam);
            Victim = EnemyTeam->getVector()[i_enemy];
        }
        // checking if the type of the character is Cowboy
        // https://www.geeksforgeeks.org/typeid-operator-in-c-with-examples/
        if (typeid(*character) == typeid(Cowboy))
        {
            // we need to cast character to Cowboy so we can use the function of Cowboy
            Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
            // got bullet so atack
            if (cowboy->hasboolets())
            {
                cowboy->shoot(Victim);
            }
            // the cowboy need to reload
            else
            {
                cowboy->reload();
            }
        }
        // checking if the type of character is Ninja
        if (typeid(*character) == typeid(Cowboy))
        {
            // we need to cast character to Ninja so we can use the function of Ninja
            Ninja *ninja = dynamic_cast<Ninja *>(character);
            // cheking if the ninja can atack or not (1 metter or less than the victim)
            if (ninja->getLocation().distance(Victim->getLocation()) <= 1)
            {
                ninja->slash(Victim);
            }
            // the ninja need to move;
            else
            {
                ninja->move(Victim);
            }
        }
    }
}

