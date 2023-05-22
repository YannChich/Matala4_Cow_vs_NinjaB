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

/* Function to calculate the distance 
-Ex : we got (2,3) and (4,8) to calculate the distance we need to use Pythagore : Distance² = (4-2)² + (8-3)² 
                                                                                           = 29   ---> Distance = sqrt(29)
*/
double Point::distance(const Point& other) const{
    double distance = sqrt(abs((this->getY() - other.getY())*(this->getY() - other.getY()))+
    abs((this->getX() - other.getX())*(this->getX() - other.getX())));
    return distance;
}

string Point::print() const {
        return ;
    }

Point Point::moveTowards(const Point& source,const Point& destination,double distance){
    return Point();
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