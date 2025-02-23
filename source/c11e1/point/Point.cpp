#include "Point.h"

using namespace std;

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

string Point::to_string(){
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Point Point::operator+(Point& p){
    return Point(p.x + x, p.y + y);
}