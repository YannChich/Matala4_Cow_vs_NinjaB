#include "Character.hpp"
#include <vector>
#include <string>

using namespace std;

namespace ariel{

class Team{
private:
// Data of a Team 
    vector<Character*> team;
    int size;
    Character* Leader;
/*
Function to help me with the function attack
The function going to localize the closest character to the dead leader
The function return the index of the vector
*/
    int FindLeader() const;

/*
Function to help me with the function attack
The function going to localize the victim 
The function return the index of the enemy Team
*/
    int FindVictim(Team* EnemyTeam) const;

public:
/*
Constructor of Team
We got only 1 parameter : the Leader , we are going to initialize the size to 0 or 1 and build the vector in the constructor (Demo)
*/
    Team(Character* Leader);

/*
Destructor for the Team (using new in the Demo)
The destructor going to be virtual because Team2 and SmartTeam implement Team
*/
    virtual ~Team();


// To supp. the error from Tidy
    // Deleted copy constructor and copy assignment operator
    Team(const Team&) = delete;
    Team& operator=(const Team&) = delete;

    // Deleted move constructor and move assignment operator
    Team(Team&&) = delete;
    Team& operator=(Team&&) = delete;
/*
This function add a new Character to the Team
We need to adjust the size of the Team 
Exception : We need to verifiy if the team is full or not 
*/
    void add(Character* TeamMate);
    

/*
This function is the principal function. The way how the team going to atack an other team
This function going to be virtual because they way of atack is different for team2 and team3
Exception : We need to check if the Leader is alive or not, Check the enemy team and atack team
How is the atack : Chose a victim closest to the Leader. Cowboy going to play first , after the ninja will play
*/
    virtual void attack(Team* EnemyTeam);

/*
This function going to return the number of TeamMate alive in a Team
*/
    int stillAlive() const;

/*
This function going to print every member of the Team by using they print function
I will add the Char : T before to know that i'm printing a Team 
*/
    virtual string print() const;

// Getter for the private data
/*
This function going to return the size of a Team
*/
    int getSizeTeam() const;

// Getter for the vector
    vector<Character*> getVector() const;

// Getter for the leader
    Character* getLeader() const;
    };
}
