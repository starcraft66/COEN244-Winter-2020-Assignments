#include "Triangle.hpp"

Triangle::Triangle(Point& p1, Point& p2, Point& p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

std::string Triangle::Print()
{
    return "Triangle " + std::to_string(this->p1.GetX()) + " " + std::to_string(this->p1.GetY()) + std::to_string(this->p2.GetX()) + " " + std::to_string(this->p2.GetY()) + " " + std::to_string(this->p3.GetX()) + " " + std::to_string(this->p3.GetY());
}