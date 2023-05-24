#include "SmartTeam.hpp"

using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character* Leader):Team(Leader){}

size_t SmartTeam::FindVictim_Cowboy(Team* EnemyTeam, Point& position) const{
    double max_distance = -1; 
    size_t max_distance_index = 0; 
    size_t lowest_HP_index = 0;
    bool has_low_HP_target = false;

    // For each character in the enemy team
    for (size_t i = 0; i < EnemyTeam->getVector().size(); ++i)
    {
        Character *character = EnemyTeam->getVector()[i];

        // Skip if the character is dead
        if (!character->isAlive()) continue;
        
        // If this character has 10HP or less and we don't already have a low HP target
        if(character->getHealth() <= 10 && !has_low_HP_target){
            has_low_HP_target = true;
            lowest_HP_index = i;
        }

        // Calculate the distance from the position to this character
        double distance = position.distance(character->getLocation());

        // If this character is further so we are updating the index
        if (distance > max_distance)
        {
            max_distance = distance;
            max_distance_index = i;
        }
    }

    // If we found a character with 10HP or less, return that one
    if (has_low_HP_target){
        return lowest_HP_index;
    }
    else{
        // Otherwise, return the character who was furthest away
        return max_distance_index;
    }
}

size_t SmartTeam::FindClosestVictim(Team* EnemyTeam, Point& position) const{
    double min_distance = -1; 
    size_t min_distance_index = 0;

    // For each character in the enemy team
    for (size_t i = 0; i < EnemyTeam->getVector().size(); ++i)
    {
        Character *character = EnemyTeam->getVector()[i];

        // Skip if the character is dead
        if (!character->isAlive()) continue;

        // Calculate the distance from the position to this character
        double distance = position.distance(character->getLocation());

        // If this character is closer we are updating the index
        if (distance < min_distance)
        {
            min_distance = distance;
            min_distance_index = i;
        }
    }

    // Return the index of the character who was closest
    return min_distance_index;
}

/*
This function is the principal function of SmartTeam.
We are keeping the same Exception from Team but the way of the attack is different
How is the attack : Cowboys will always attack targets furthest from their Leader's position. 
But if there is a target that has 10 HP it will kill it.
Ninjas will attack the target closest to their position
*/
void SmartTeam::attack(Team* EnemyTeam){
    // if the EnemyTeam is null we need to throw an invalid argument
    if(EnemyTeam == nullptr){
        throw invalid_argument("The EnemyTeam is a null ptr");
    }
    // If the EnemyTeam is dead throw an error
    if (EnemyTeam->stillAlive() == 0)
    {
        throw runtime_error("The enemy Team is dead");
    }
    // We need to check if the Leader is alive or not
    Point pos_Leader;
    if (this->getLeader()->isAlive() == false)
    {
        // finding the index of the Leader
        size_t i_leader = FindLeader();
        // updating the new Leader
        this->setLeader(this->getVector()[i_leader]);
        pos_Leader = this->getLeader()->getLocation();
    }
    
    // Cowboys attack
    for (Character *character : this->getVector())
    {
        // passing to the next Character if he is dead
        if(character->isAlive() == false){
            continue;
        }
        // break if the enemyTeam is dead
        if(EnemyTeam->stillAlive() == false){
            break;
        }
        // checking if the type of the character is Cowboy
        if (typeid(*character) == typeid(Cowboy))
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
            size_t i_enemy = FindVictim_Cowboy(EnemyTeam,pos_Leader);
            Character *Victim = EnemyTeam->getVector()[i_enemy];

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
    }
    
    Point pos_Ninja;
    // Ninjas attack
    for (Character *character : this->getVector())
    {   
        // passing to the next Character if he is dead
        if(character->isAlive() == false){
            continue;
        }
        // break if the enemyTeam is dead
        if(EnemyTeam->stillAlive() == false){
            break;
        }
        // checking if the type of the character is Ninja
        if (typeid(*character) == typeid(OldNinja) || typeid(*character) == typeid(YoungNinja) || typeid(*character) == typeid(TrainedNinja)) 
        {

            Ninja *ninja = dynamic_cast<Ninja *>(character);
            pos_Ninja = ninja->getLocation();
            size_t i_enemy = FindClosestVictim(EnemyTeam, pos_Ninja);
            Character *Victim = EnemyTeam->getVector()[i_enemy];

            if (ninja->getLocation().distance(Victim->getLocation()) <= 1)
            {
                ninja->slash(Victim);
            }
            //the ninja needs to move
            else
            {
                ninja->move(Victim);
            }
        }
    }
}


