#ifndef OUTPATIENT_H_
#define OUTPATIENT_H_
#include "Person.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "Doctor.hpp"

class OutPatient : Person
{
    int id_;
    std::string name_;
    Date appointment_date_;
    Time appointment_time_;
    double hospital_charge_;
    Doctor* doctor_;
public:
    OutPatient(int, std::string, Date, Time, double, Doctor*);
    void SetName(std::string);
    std::string GetName();
    int GetId();
    void Print();
};
#endif