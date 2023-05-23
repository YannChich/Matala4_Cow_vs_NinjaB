#include "Team.hpp"

using namespace std;
using namespace ariel;


Team::Team(Character* Leader){
    if(Leader == nullptr){
        throw invalid_argument("The ptr to the Leader is Null");
    }
    this->Leader = Leader;
    this->team.push_back(Leader);
    this->size = 1;
}

Team::~Team() {
    for (Character* character : team) {
        delete character;
    }
}
// We need to check who is the Leader and run on the vector to find who is the closest character to the old leader
int Team::FindLeader() const{
    // the return index of the new Leader
    int i = -1;
    Point pos_Leader = this->Leader->getLocation();
    Point temp_pos;
    Point distance_Leader;
    // running into the vector of Character
    for (size_t i = 0; i < this->size; i++)
    {
        temp_pos = this->team[i]->getLocation();
        distance_Leader = temp_pos.distance(pos_Leader);
    }
    
}

int Team::FindVictim(Team* EnemyTeam) const{
    return 0;
}

void Team::add(Character* TeamMate){
    return;
}

void Team::attack(Team* EnemyTeam){
    return;
}

int Team::stillAlive() const{
    return 0;
}

string Team::print() const{
    return "";
}

int Team::getSizeTeam() const{
    return this->size;
}

vector<Character*> Team::getVector() const{
    return this->team;
}

Character* Team::getLeader() const{
    return this->Leader;
}
