#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name,Point location,int health,int speed):Character(name,location,health),Speed(speed){}

void Ninja::move(Character* enemy){
    return;
}

void Ninja::slash(Character* enemy){
    return;
}

string Ninja::print()const{
    return "";
}

int Ninja::getSpeed() const{
    return this->Speed;
}

YoungNinja::YoungNinja(string name,Point location):Ninja(name,location,100,14){}

TrainedNinja::TrainedNinja(string name,Point location):Ninja(name,location,120,12){}

OldNinja::OldNinja(string name,Point location):Ninja(name,location,150,8){}