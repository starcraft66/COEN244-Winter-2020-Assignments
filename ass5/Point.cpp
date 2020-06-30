#include "Point.hpp"
#include <iostream>

Point::Point()
{
    this->x_coor = 0.0;
    this->y_coor = 0.0;
}

Point::Point(double x, double y)
{
    this->x_coor = x;
    this->y_coor = y;
}

double Point::GetX()
{
    return this->x_coor;
}

double Point::GetY()
{
    return this->y_coor;
}

std::string Point::Print()
{
    return "Point " + std::to_string(this->x_coor) + " " + std::to_string(this->y_coor);
}