#include "food.hpp"

// gotta change size to protected instead of private
double Pizza::getCost() const
{
    if (this->size == "small")
    {
        return this->baseCost;
    }
    else if (this->size == "medium")
    {
        return this->baseCost * 1.5;
    }
    else if (this->size == "large")
    {
        return this->baseCost * 2;
    }
    return 0;
}

double Softdrink::getCost() const
{
    if (this->size == "small")
    {
        return this->baseCost * 1.5;
    }
    else if (this->size == "medium")
    {
        return this->baseCost * 2;
    }
    else if (this->size == "large")
    {
        return this->baseCost * 2.5;
    }
    return 0;
}