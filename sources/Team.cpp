#include "Team.hpp"
#include <limits>
#include <typeinfo>

using namespace std;
using namespace ariel;

Team::Team(Character *Leader) : Leader(Leader)
{
    // checking if the Leader is already a Leader in a Team
    if (Leader->getInTeam()){
        throw runtime_error("The leader is already in a team");
    }
    this->team.push_back(Leader);
    this->size = 1;
    Leader->setInTeam(true);
}

Team::~Team()
{
    for (Character *character : team)
    {
        delete character;
    }
}
// We need to check who is the Leader and run on the vector to find who is the closest character to the old leader
size_t Team::FindLeader() const
{
    // the return index of the new Leader
    size_t index = 0;
    Point pos_Leader = this->Leader->getLocation();
    Point temp_pos;
    double Mindistance_Leader = numeric_limits<double>::max();
    double tempDistance;
    // running into the vector of Character
    for (size_t i = 0; i < this->size; i++)
    {
        // checking only if the Character is alive
        if (this->team[i]->isAlive())
        {
            // if the Character is the leader we need to pass to the next character
            if (this->team[i] == this->Leader)
            {
                continue;
            }
            // Calculating the distance with the character and the leader and with a if statement , updating the index of the new leader
            temp_pos = this->team[i]->getLocation();
            tempDistance = temp_pos.distance(pos_Leader);
            if (tempDistance < Mindistance_Leader)
            {
                Mindistance_Leader = tempDistance;
                index = i;
            }
        }
    }
    return index;
}
// We need to find the closest enemy and return his index
size_t Team::FindVictim(Team *EnemyTeam) const
{
    size_t index = 0;
    Point pos_Leader = this->Leader->getLocation();
    Point temp_pos;
    double Mindistance_Leader = numeric_limits<double>::max();
    double tempDistance;
    // running into the vector of Character
    for (size_t i = 0; i < EnemyTeam->size; i++)
    {
        // Finding the victim only if the Character is Alive
        if (EnemyTeam->team[i]->isAlive())
        {
            // Calculating the distance with the character and the leader and with a if statement , updating the index of the new leader
            temp_pos = EnemyTeam->team[i]->getLocation();
            tempDistance = temp_pos.distance(pos_Leader);
            if (tempDistance < Mindistance_Leader)
            {
                Mindistance_Leader = tempDistance;
                index = i;
            }
        }
    }
    return index;
}

/*
This function add a new Character to the Team
We need to adjust the size of the Team
Exception : We need to verifiy if the team is full or not
*/
void Team::add(Character *TeamMate)
{
    if(TeamMate->getInTeam()){
        throw runtime_error("Already in a Team");
    }
    // the Team is full we need to throw invalide argument
    if (this->size == 10)
    {
        throw runtime_error("The team is full.");
    }
    this->team.push_back(TeamMate);
    this->size++;
    TeamMate->setInTeam(true);
}

/*
This function is the principal function. The way how the team going to atack an other team
This function going to be virtual because they way of atack is different for team2 and team3
Exception : We need to check if the Leader is alive or not, Check the enemy team and atack team
How is the atack : Chose a victim closest to the Leader. Cowboy going to play first , after the ninja will play
Help on : https://www.geeksforgeeks.org/typeid-operator-in-c-with-examples/  for typeid()
*/
void Team::attack(Team *EnemyTeam)
{
    // if the EnemyTeam is null we need to throw a invalid argument
    if(EnemyTeam == nullptr){
        throw invalid_argument("The EnemyTeam is a null ptr");
    }
    // If the EnemyTeam is dead throw a error
    if (EnemyTeam->stillAlive() == 0)
    {
        throw runtime_error("The enemy Team is dead");
    }
    // We need to check if the Leader is alive or not
    if (this->Leader->isAlive() == false)
    {
        // finding the index of the Leader
        size_t i_leader = FindLeader();
        // updating the new Leader
        this->setLeader(this->team[i_leader]); //Leader = this->team[i_leader];
    }
    // We need now to find the enemy character closest to the Leader
    size_t i_enemy = FindVictim(EnemyTeam);
    Character *Victim = EnemyTeam->team[i_enemy];
    // Now every Character of the atack's Team going to atack the enemy
    // First every CowBoy atack the enemy if they got 0 bullet they are going to reload
    //cout << "The leader before atack : " << this->Leader->print() << endl;
    //cout << "The victim before atack : " << Victim->print() << endl;
    for (Character *character : this->team)
    {
        // passing to the next Character if he is dead
        if(character->isAlive() == false){
            continue;
        }
        // break if the enemyTeam is dead
        if(EnemyTeam->stillAlive() == false){
            break;
        }
        // Every run on the next cowboy we need to check if the victim is alive or not
        if (Victim->isAlive() == false)
        {
            i_enemy = FindVictim(EnemyTeam);
            Victim = EnemyTeam->team[i_enemy];
            //cout << "New Victim : " << Victim->print() << endl;
        }
        // checking if the type of the character is Cowboy
        // https://www.geeksforgeeks.org/typeid-operator-in-c-with-examples/
        if (typeid(*character) == typeid(Cowboy))
        {
            // we need to cast character to Cowboy so we can use the function of Cowboy
            Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
            // got bullet so atack
            //out << "The cowboy atack : " << cowboy->print() << endl;
            if (cowboy->hasboolets())
            {
                cowboy->shoot(Victim);
            }
            // the cowboy need to reload
            else
            {
                cowboy->reload();
            }
            //cout << "The victim stat: " << Victim->print() << endl;
        }
    }
    // Now the Ninja going to atack
    // Now every Character of the atack's Team going to atack the enemy
    // First every CowBoy atack the enemy if they got 0 bullet they are going to reload
    for (Character *character : this->team)
    {   
        // passing to the next Character if he is dead
        if(character->isAlive() == false){
            continue;
        }
        // break if the enemyTeam is dead
        if(EnemyTeam->stillAlive() == false){
            break;
        }
        // Every run on the next cowboy we need to check if the victim is alive or not
        if (Victim->isAlive() == false)
        {
            i_enemy = FindVictim(EnemyTeam);
            Victim = EnemyTeam->team[i_enemy];
            //cout << "New Victim : " << Victim->print() << endl;
        }
        // checking if the type of the character is Ninja
        // https://www.geeksforgeeks.org/typeid-operator-in-c-with-examples/
        if (typeid(*character) == typeid(OldNinja) || typeid(*character) == typeid(YoungNinja) || typeid(*character) == typeid(TrainedNinja)) {
            // we need to cast character to Ninja so we can use the function of Ninja
            Ninja *ninja = dynamic_cast<Ninja *>(character);
            // cheking if the ninja can atack or not (1 metter or less than the victim)
            //cout << "The ninja atack : " << ninja->print() << endl;
            if (ninja->getLocation().distance(Victim->getLocation()) <= 1)
            {
                ninja->slash(Victim);
            }
            // the ninja need to move;
            else
            {
                ninja->move(Victim);
            }
            //cout << "The victim stat: " << Victim->print() << endl;
        }
    }
}

int Team::stillAlive() const
{
    int stillAlive = 0;
    // Running on the Team and using the function bool isAlive to count 
    for (Character *character : this->team){
        if(character->isAlive()){
            stillAlive++;
        }
    }
    return stillAlive;
}

string Team::print() const
{
    string result = "Team Members:\n";

    for (Character* character : team) {
        result += character->print() + "\n";
    }

    return result;
}


void Team::setLeader(Character* new_Leader){
    this->Leader = new_Leader;
}

int Team::getSizeTeam() const
{
    return this->size;
}

vector<Character *> Team::getVector() const
{
    return this->team;
}

Character *Team::getLeader() const
{
    return this->Leader;
}
