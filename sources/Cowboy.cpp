#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name,Point location):Character(name,location,110),bullets(6){};

void Cowboy::shoot(Character* enemy){
    return;
}

bool Cowboy::hasboolets() const{
    return true;
}

void Cowboy::reload(){
    return;
}

string Cowboy::print()const{
    return "";
}