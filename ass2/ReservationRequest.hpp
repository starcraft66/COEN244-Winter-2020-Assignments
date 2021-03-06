#ifndef RESERVATION_REQUEST_H_
#define RESERVATION_REQUEST_H_
#include <array>
#include "Person.hpp"
class ReservationRequest
{
    Person* person_;
    static int counter_;
    int number_;
    Date date_;
    std::string start_;
    std::string dest_;
    int seats_;
public:
    ReservationRequest();
    ~ReservationRequest();
    ReservationRequest(Person*, const Date&, const std::string&, const std::string&, int);
    int GetNumber();
    void SetPerson(Person&);
    Person* GetPerson();
    void SetDate(Date);
    Date GetDate();
    void SetStart(std::string);
    std::string GetStart();
    void SetDest(std::string);
    std::string GetDest();
    void SetSeats(int);
    int GetSeats();
    void Print();
};
#endif