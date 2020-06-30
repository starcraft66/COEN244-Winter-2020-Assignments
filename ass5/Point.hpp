#ifndef POINT_H_
#define POINT_H_
#include "Shape.hpp"
#include <string>
class Point : Shape
{
    double x_coor, y_coor;
public:
    Point();
    Point(double, double);
    double GetX();
    double GetY();
    std::string Print();
};
#endif