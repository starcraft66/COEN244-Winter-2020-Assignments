#include <string>
#include <iostream>
#include "ReservationRequest.hpp"

int ReservationRequest::counter_;

ReservationRequest::ReservationRequest()
{

}

ReservationRequest::~ReservationRequest()
{
    std::cout << "ReservationRequest object deleted" << std::endl;
}

ReservationRequest::ReservationRequest(Person& person, Date date, std::string start, std::string dest, int seats)
{
    this->number_ = this->counter_;
    this->counter_++;
    this->person_ = person;
    this->date_ = date;
    this->start_ = start;
    this->dest_ = dest;
    this->seats_ = seats;
}

int ReservationRequest::GetNumber()
{
    return this->number_;
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

void ReservationRequest::Print()
{
    std::cout << "ReservationRequest: Number: " << this->GetNumber() << " Person: Name: " <<
    this->GetPerson().GetName() << "Date: Day: " << this->GetDate().GetDay() << " Month: " <<
    this->GetDate().GetMonth() << " Year: " << this->GetDate().GetYear() << " Start: " <<
    this->GetStart() << " Destination: " << this->GetDest() << " Seats: " << this->GetSeats() << std::endl;
}