#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <array>
#include "Person.hpp"
class Passenger
{
    Person person_;
    std::array<int, 5> trips_;
public:
    Passenger();
    Passenger(Person);
    Passenger(Person, std::array<int, 5>);
    void SetPerson(Person);
    Person GetPerson();
    void SetTrips(std::array<int, 5>);
    std::array<int, 5> GetTrips();
};
#endif