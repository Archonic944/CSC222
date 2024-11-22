#include <string>

struct Point {
    Point();
    Point(double x, double y);
    double x;
    double y;

    Point operator+(Point& p);
    std::string to_string();
};