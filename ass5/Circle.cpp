#include "Circle.hpp"

Circle::Circle(Point& p, double radius)
{
    this->p = p;
    this->radius = radius;
}

std::string Circle::Print()
{
    return "Circle " + std::to_string(this->p.GetX()) + " " + std::to_string(this->p.GetY()) + " " + std::to_string(this->radius);
}