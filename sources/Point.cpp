#include "Point.hpp"
#include <cmath> // To use the function sqrt
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;

Point::Point(){
    this->graph_X = 0;
    this->graph_Y = 0;
}

Point::Point(double graph_x,double graph_y): graph_X(graph_x),graph_Y(graph_y){}

Point::Point(const Point& other):graph_X(other.graph_X), graph_Y(other.graph_Y) {}

Point::Point(Point&& other) noexcept : graph_X(other.graph_X), graph_Y(other.graph_Y) {}

/* Function to calculate the distance 
-Ex : we got (2,3) and (4,8) to calculate the distance we need to use Pythagore : Distance² = (4-2)² + (8-3)² 
                                                                                           = 29   ---> Distance = sqrt(29)
*/
double Point::distance(const Point& other) const{
    double dist_X = pow(other.graph_X - this->graph_X,2);
    double dist_Y = pow(other.graph_Y - this->graph_Y,2);
    double distance = sqrt(dist_X + dist_Y);
    return distance;
}

string Point::print() const {
    string x_str = to_string(graph_X);
    string y_str = to_string(graph_Y);
    string result = "(" + x_str + "," + y_str + ")";
    return result;
}


Point Point::moveTowards(const Point& source,const Point& destination,double dist){
    // distance between source and destination
    double Point_distance = source.distance(destination);
    // if the argument distance is negatif we need to throw a invalid argument
    if(dist < 0){
        throw invalid_argument("A distance cannot be negatif");
    }
    // if the source and destination is the same point 
    if(source == destination){
        return source;
    }
    // if the distance between the points is smaller than the argument dist we need to return destination
    if(Point_distance <= dist){
        return destination;
    }
    // We need to move the point source to destination with the argument dist 
    double ratio = dist / Point_distance;
    double newX = source.graph_X + (destination.graph_X - source.graph_X) * ratio;
    double newY = source.graph_Y + (destination.graph_Y - source.graph_Y) * ratio;

    return Point(newX, newY);

}

double Point::getX() const{
    return this->graph_X;
}

double Point::getY() const{
    return this->graph_X;
}

void Point::setX(double new_x){
    this->graph_X = new_x;
}

void Point::setY(double new_y){
    this->graph_Y = new_y;
}