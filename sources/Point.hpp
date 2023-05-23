#pragma once
#include <iostream>
#include <string>
using namespace std;


namespace ariel{

class Point{

private :
    // Data for one point (x,y)
    double graph_X;
    double graph_Y;

public :
// Constructors
    // Default constructor
    Point();

    // Parameterized
    Point(double graph_x,double graph_y);

/* Function to calculate the distance 
-Ex : we got (2,3) and (4,8) to calculate the distance we need to use Pythagore : Distance² = (4-2)² + (8-3)² 
                                                                                           = 29   ---> Distance = sqrt(29)
*/
    double distance(const Point& other) const;

/* Function to print the point
-we need to return an object of ostringstream to use the function like in the demo.
-Ex : we got P1 if we print him it's look like : (x,y)
*/
    string print() const;

/* Function moveTowards return the closest point to the dest Point
-The function got 3 arguments : the distance , the source and the desitination
-The function going to be static because we dont need instance of the class Point to use it
-Logic : 
*/
    static Point moveTowards(const Point& source,const Point& destination,double dist);

// Funcion Getter and Setter for Point
    double getX() const;
    double getY() const;
    void setX(double new_x);
    void setY(double new_y);

// Operator == & =
    bool operator==(const Point& other) const {
        return (graph_X == other.graph_X) && (graph_Y == other.graph_Y);
    }
    // Copie operator
    Point& operator=(const Point& other){
        if(this != &other){ // Check if the objects is different
            graph_X = other.graph_X;
            graph_Y = other.graph_Y;
        }
        return *this; 
    }
  };
}