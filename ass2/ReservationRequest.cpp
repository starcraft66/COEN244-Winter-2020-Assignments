#include <string>
#include "ReservationRequest.hpp"

ReservationRequest::ReservationRequest()
{

}

ReservationRequest::ReservationRequest(Person person, Date date, std::string start, std::string dest, int seats)
{
    this->person_ = person;
    this->date_ = date;
    this->start_ = start;
    this->dest_ = dest;
    this->seats_ = seats;
}

void ReservationRequest::SetPerson(Person person)
{
    this->person_ = person;
}

Person ReservationRequest::GetPerson()
{
    return this->person_;
}

void ReservationRequest::SetDate(Date date)
{
    this->date_ = date;
}

Date ReservationRequest::GetDate()
{
    return this->date_;
}

void ReservationRequest::SetStart(std::string start)
{
    this->start_ = start;
}

std::string ReservationRequest::GetStart()
{
    return this->start_;
}

void ReservationRequest::SetDest(std::string dest)
{
    this->dest_ = dest;
}

std::string ReservationRequest::GetDest()
{
    return this->dest_;
}

void ReservationRequest::SetSeats(int seats)
{
    this->seats_ = seats;
}

int ReservationRequest::GetSeats()
{
    return this->seats_;
}