#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name,Point location,int health,int speed):Character(name,location,health),Speed(speed){}

void Ninja::move(Character* enemy){
    // We need to use the function MoveToward with the speed of the ninja
    Point New_Location = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->Speed);
    this->setLocation(New_Location);
}

/*
-This function going to represent the action of the Ninja : slash someone
-Exception : if the enemy is not a meter away , there is no damage
-Damage of slash : -40HP
*/
void Ninja::slash(Character* enemy){
    // going to check if the enemy is a meter away or not 
    // if the ninja is 1 meter or less than the enemy he can do 40 damage
    if(this->getLocation().distance(enemy->getLocation()) <= 1){
        enemy->hit(40);
    }
}

string Ninja::print()const{
    // the same print like the CowBoy but with a N and not a C
    if(this->isAlive() == false){
        return "Name : N ("+this->getName()+") , Location : "+this->getLocation().print();
    }
    string health_str = to_string(this->getHealth());
    return "Name : N "+this->getName()+" , Health : "+health_str+ "Location : "+this->getLocation().print();
}

int Ninja::getSpeed() const{
    return this->Speed;
}
