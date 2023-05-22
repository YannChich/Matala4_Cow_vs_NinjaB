#include "Character.hpp"

using namespace std;
using namespace ariel;

Character::Character(string name,Point location,int health): location(location),health(health),name(name),inTeam(false){}

bool Character::isAlive() const{
    return true;
}

double Character::distance(Character* character) const{
    return 0;
}

void Character::hit(int damage){
    return;
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
void Character::setInTeam(bool InTeam){
    this->inTeam = InTeam;
}
void Character::setLocation(Point& new_Location){
    this->location = new_Location;
}