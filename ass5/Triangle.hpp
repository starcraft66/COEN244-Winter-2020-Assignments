#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Shape.hpp"
#include "Point.hpp"
#include <string>
class Triangle : Shape
{
    Point p1, p2, p3;
public:
    Triangle(Point&, Point&, Point&);
    std::string Print();
};
#endif