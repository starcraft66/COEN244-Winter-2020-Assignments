#include "Bed.hpp"
#include <iostream>

Bed::Bed()
{
    this->id_ = 0;
    this->occupied_ = 0;
}

Bed::Bed(int id, bool occupied)
{
    this->id_ = id;
    this->occupied_ = occupied;
}

bool Bed::GetOccupied()
{
    return this->occupied_;
}

void Bed::SetOccupied(bool occupied)
{
    this->occupied_ = occupied;
}

int Bed::GetId()
{
    return this->id_;
}

void Bed::Print()
{
    std::cout << "Bed{id=" << this->id_ << ",occupied=" << this->occupied_ << "}";
}