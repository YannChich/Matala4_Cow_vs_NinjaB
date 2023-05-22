#include "doctest.h"
#include "sources/Team.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("Test Point class") {
    SUBCASE("Test default constructor") {
        Point p;

        CHECK(p.getX() == 0);
        CHECK(p.getY() == 0);
    }

    SUBCASE("Test parameterized constructor") {
        Point p(3,4);

        CHECK(p.getX() == 3);
        CHECK(p.getY() == 4);
    }

    SUBCASE("Test distance function") {
        Point p1(0,0);
        Point p2(0,4);
        // The distance between p1 & p2 is equal to : Distance² = 0² + 4² ---> Distance = sqrt(16) == 4
        CHECK(p1.distance(p2) == 4);
        CHECK(p2.distance(p1) == 4);
        CHECK_FALSE(p1.distance(p2) == 0);
    }

    SUBCASE("Test print function") {
        Point p(3,4);
        string expected_output = "(3,4)";

        CHECK(p.print() == expected_output);
        CHECK_NOTHROW(p.print());
    }

    SUBCASE("Test moveTowards function") {
        Point source(0, 0);
        Point destination(0, 2);
        double distance = 1;
        /* To calculate the closest point from the source we need to follow few steps :
                            - Calculate the distance between source and destination 
                            - Calculate the Ratio between the parameter distance and the distance
                            - Find with the ratio the cloest point
                            */
        Point result = Point::moveTowards(source, destination, distance);
        CHECK(result.getX() == 0);
        CHECK(result.getY() == 1);

        CHECK(result.distance(destination) == 1);
    }

    SUBCASE("Test getters and setters") {
        Point p;

        p.setX(3);
        p.setY(4);

        CHECK(p.getX() == 3);
        CHECK(p.getY() == 4);
    }
}


class TestCharacter : public Character {
public:
    TestCharacter(string name, Point location, int health)
        : Character(name, location, health) {}
    
    string print() const override {
        return "TestCharacter";
    }
};

TEST_CASE("Character tests") {
    Point loc(0,0);
    TestCharacter character("Test", loc, 100);

    SUBCASE("Initial values") {
        CHECK(character.isAlive() == true);
        CHECK(character.getHealth() == 100);
        CHECK(character.getName() == "Test");
        CHECK(character.getLocation().getX() == 0);
        CHECK(character.getLocation().getY() == 0);
        CHECK(character.getInTeam() == false);
    }

    SUBCASE("Distance calculation") {
        Point loc2(0,5);
        TestCharacter character2("Test2", loc2, 100);
        CHECK(character.distance(&character2) == 5);
    }

    SUBCASE("Hit and health reduction") {
        character.hit(20);
        CHECK(character.getHealth() == 80);
        character.hit(100);
        CHECK(character.getHealth() == -20);
    }

    SUBCASE("IsAlive checks") {
        character.hit(20);
        CHECK(character.isAlive() == true);
        CHECK(character.getHealth() == 80);
        character.hit(80);
        CHECK(character.isAlive() == false);
        CHECK(character.getHealth() == 0);
        CHECK_THROWS(character.hit(80));

    }

    SUBCASE("Setters") {
        character.setInTeam(true);
        CHECK(character.getInTeam() == true);
        Point new_loc(3, 4);
        character.setLocation(new_loc);
        CHECK(character.getLocation().getX() == 3);
        CHECK(character.getLocation().getY() == 4);
    }
}

TEST_CASE("Cowboy tests") {
    Point loc(1, 2);
    Cowboy cowboy("Cowboy1", loc);

    CHECK(cowboy.getName() == "Cowboy1");
    CHECK(cowboy.getHealth() == 110);
    CHECK(cowboy.getLocation().getX() == 1);
    CHECK(cowboy.getLocation().getY() == 2);
    CHECK(cowboy.hasboolets() == true);
    CHECK_THROWS(cowboy.reload());

    SUBCASE("Shooting and reloading") {
        Point loc2(3, 4);
        Cowboy target("Cowboy2", loc2);
        int initialHealth = target.getHealth();

        cowboy.shoot(&target);
        CHECK(target.getHealth() == initialHealth - 10);
        CHECK(cowboy.hasboolets() == true); 
        // shoot 5 bullets and it's need to reload
        for (int i = 0; i < 5; i++) {
            cowboy.shoot(&target);
        }
        CHECK(cowboy.hasboolets() == false); 

        cowboy.reload();
        CHECK(cowboy.hasboolets() == true); 
    }

    SUBCASE("Print method") {
        CHECK(cowboy.print().substr(0, 9) == "C(Cowboy1");
    }
}

TEST_CASE("Ninja tests") {
    Point loc1(0, 0);
    Point loc2(1, 1);

    YoungNinja youngNinja("YoungNinja", loc1);
    TrainedNinja trainedNinja("TrainedNinja", loc2);
    OldNinja oldNinja("OldNinja", loc2);

    SUBCASE("Creation and initial values") {
        CHECK(youngNinja.getName() == "YoungNinja");
        CHECK(youngNinja.getHealth() == 100);
        CHECK(youngNinja.getSpeed() == 14);

        CHECK(trainedNinja.getName() == "TrainedNinja");
        CHECK(trainedNinja.getHealth() == 120);
        CHECK(trainedNinja.getSpeed() == 12);

        CHECK(oldNinja.getName() == "OldNinja");
        CHECK(oldNinja.getHealth() == 150);
        CHECK(oldNinja.getSpeed() == 8);
    }

    SUBCASE("Moving and slashing") {
        youngNinja.move(&trainedNinja);
        CHECK(youngNinja.distance(&trainedNinja) <= 1);

        int initialHealth = trainedNinja.getHealth();
        youngNinja.slash(&trainedNinja);
        CHECK(trainedNinja.getHealth() == initialHealth - 40);
    }

    SUBCASE("Print method") {
        CHECK(youngNinja.print().substr(0, 11) == "N(YoungNinja,100,(0,0)");
        CHECK(trainedNinja.print().substr(0, 13) == "N(TrainedNinja,120,(1,1)");
        CHECK(oldNinja.print().substr(0, 9) == "N(OldNinja,150,(1,1)");
    }
}


TEST_CASE("Team tests") {
    Point loc1(0, 0);
    Point loc2(1, 1);
    Point loc3(2, 2);

    Cowboy cowboy("Cowboy", loc1);
    YoungNinja youngNinja("YoungNinja", loc1);
    TrainedNinja trainedNinja("TrainedNinja", loc2);
    OldNinja oldNinja("OldNinja", loc3);

    Team team1(&cowboy);
    Team2 team2(&youngNinja);
    SmartTeam smartTeam(&trainedNinja);

    SUBCASE("Adding team members") {
        team1.add(&youngNinja);
        CHECK(team1.getSizeTeam() == 2);
        CHECK(team1.stillAlive() == 2);
    }

    SUBCASE("Attacks and team status") {
        team1.add(&youngNinja);
        team1.add(&trainedNinja);

        team2.add(&oldNinja);
        team2.add(&cowboy);

        team1.attack(&team2);
        CHECK(team2.stillAlive() <= 2);

        smartTeam.attack(&team1);
        CHECK(team1.stillAlive() <= 3);
    }

    SUBCASE("Print method") {
        team1.add(&youngNinja);
        team1.add(&trainedNinja);

        CHECK(team1.print().substr(0, 2) == "T(");
        CHECK(team2.print().substr(0, 3) == "T2(");
        CHECK(smartTeam.print().substr(0, 3) == "ST(");
    }
}