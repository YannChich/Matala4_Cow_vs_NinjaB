#include "Character.hpp"

using namespace std;
using namespace ariel;

Character::Character(string name,Point location,int health): location(location),health(health),name(name),inTeam(false){}

bool Character::isAlive() const{
    if(this->health == 0){
        return false;
    }
    return true;
}

double Character::distance(Character* character) const{
    return this->location.distance(character->location);
}

void Character::hit(int damage){
    // if damage > health , we need to set the health to 0 and not have a negatif value
    if(damage > this->health){
        setHealth(0);
    }
    // we need to substract to the health the amount of damage
    this->health = this->health - damage;
}

int Character::getHealth() const{
    return this->health;
}
string Character::getName() const{
    return this->name;
}
Point Character::getLocation() const{
    return this->location;
}
bool Character::getInTeam() const{
    return this->inTeam;
}
void Character::setHealth(int new_health){
    this->health = new_health;
}
void Character::setInTeam(bool InTeam){
    this->inTeam = InTeam;
}
void Character::setLocation(Point& new_Location){
    this->location = new_Location;
}