#include <string>
#include <iostream>
#include "Passenger.hpp"

Passenger::Passenger()
{

}

Passenger::~Passenger()
{
    std::cout << "Passenger object deleted" << std::endl;
}

Passenger::Passenger(Person person)
{
    this->person_ = person;
    this->trips_ = {0};
}

Passenger::Passenger(Person person, std::array<int, 5> trips)
{
    this->person_ = person;
    this->trips_ = trips;
}

Person Passenger::GetPerson()
{
    return this->person_;
}

void Passenger::SetPerson(Person person)
{
    this->person_ = person;
}

std::array<int, 5> Passenger::GetTrips()
{
    return this->trips_;
}

void Passenger::AddTrip(int reservation_id)
{
    for (int i = 0; i < trips_.size(); i++)
    {
        if (this->trips_[i] == 0)
        {
            this->trips_[i] = reservation_id;
            return;
        }
    }
    std::cout << "too many trips for passenger";
    exit(1);
    //throw "too many trips for passenger";
}

void Passenger::Print()
{
    std::cout << "Passenger: Person: Name: " << this->GetPerson().GetName() << " Trips: ";
    for (int trip : this->GetTrips())
    {
        std::cout << trip << ", ";
    }
}