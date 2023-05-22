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

double Point::distance(const Point& other) const{ return 0; }

string Point::print() const {
        return "";
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