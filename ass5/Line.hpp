#ifndef LINE_H_
#define LINE_H_
#include "Shape.hpp"
#include "Point.hpp"
#include <string>
class Line : Shape
{
    Point p1, p2;
public:
    Line(Point&, Point&);
    std::string Print();
};
#endif