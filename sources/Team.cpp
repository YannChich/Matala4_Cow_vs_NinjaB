#include "Team.hpp"

using namespace std;
using namespace ariel;

// Part of Team

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

int Team::FindLeader() const{
    return 0;
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
