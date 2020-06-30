#include "Line.hpp"
#include <string>

Line::Line(Point& p1, Point& p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

std::string Line::Print()
{
    return "Line " + std::to_string(this->p1.GetX()) + " " + std::to_string(this->p1.GetY()) + std::to_string(this->p2.GetX()) + " " + std::to_string(this->p2.GetY());
}