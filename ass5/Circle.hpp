#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Shape.hpp"
#include "Point.hpp"
#include <string>
class Circle : Shape
{
    Point p;
    double radius;
public:
    Circle(Point&, double);
    std::string Print();
};
#endif