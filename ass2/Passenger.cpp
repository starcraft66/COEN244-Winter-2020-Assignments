#include <string>
#include "Passenger.hpp"

Passenger::Passenger()
{

}

Passenger::Passenger(Person person)
{
    this->person_ = person;
    this->trips_ = std::array<int, 5>();
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

void Passenger::SetTrips(std::array<int, 5> trips)
{
    this->trips_ = trips;
}