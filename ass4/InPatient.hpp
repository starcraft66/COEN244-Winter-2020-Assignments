#ifndef INPATIENT_H_
#define INPATIENT_H_
#include "Person.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "Doctor.hpp"

class InPatient : Person
{
    int id_;
    std::string name_;
    Date admission_date_;
    Date discharge_date_;
    Doctor* doctor_;
    int bed_number_;
    double hospital_charge_;
public:
    InPatient();
    InPatient(int, std::string, Date, Date, Doctor*, int, double);
    void SetName(std::string);
    std::string GetName();
    int GetId();
    void Print();
    int GetBedNumber();
};
#endif