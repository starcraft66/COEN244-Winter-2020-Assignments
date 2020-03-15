#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Person.hpp"

class Doctor : Person
{
    int id_;
    std::string medical_license_number_;
    std::string name_;
    std::string specialty_;
    Person* patients_treated;
public:
    Doctor();
    Doctor(int, std::string, std::string, std::string);
    void SetName(std::string);
    std::string GetName();
    int GetId();
    void Print();
};
#endif