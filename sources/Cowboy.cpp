#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name,Point location):Character(name,location,110),bullets(6){};

void Cowboy::shoot(Character* enemy){
    // if the cowboy dont have bullet 
    if(this->bullets == 0){
        return;
    }
    // if the cowboy is dead
    if(this->isAlive() == false){
        return;
    }
    // We need to substract 10HP to the enemy and also substract 1 bullet to the cowboy
    enemy->hit(10);
    this->bullets = this->bullets -1;
}

bool Cowboy::hasboolets() const{
    return bullets > 0;
}

void Cowboy::reload(){
    bullets = 6;
}

string Cowboy::print()const{
    // if the cowboy is dead : name in () , and 'C' to the begining , the location : Name : C (cowboy) , Location : (0,0)
    if(this->isAlive() == false){
        return "Name : C ("+this->getName()+") , Location : "+this->getLocation().print();
    }
    string health_str = to_string(this->getHealth());
    return "Name : C "+this->getName()+" , Health : "+health_str+ "Location : "+this->getLocation().print();
}