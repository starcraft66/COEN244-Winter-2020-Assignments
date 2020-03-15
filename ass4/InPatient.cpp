#include "InPatient.hpp"
#include <iostream>

InPatient::InPatient()
{

}

InPatient::InPatient(int id, std::string name, Date admission, Date discharge, Doctor* doctor, int bed, double charge)
{
    this->id_ = id;
    this->name_ = name;
    this->admission_date_ = admission;
    this->discharge_date_ = discharge;
    this->doctor_ = doctor;
    this->bed_number_ = bed;
    this->hospital_charge_ = charge;
}

void InPatient::SetName(std::string name)
{
    this->name_ = name;
}

std::string InPatient::GetName()
{
    return this->name_;
}

int InPatient::GetId()
{
    return this->id_;
}

int InPatient::GetBedNumber()
{
    return this->bed_number_;
}

void InPatient::Print()
{
    std::cout << "InPatient{id=" << this->id_ << ",name=" << this->name_ << ",admission_date=";
    this->admission_date_.Print();
    std::cout << ",discharge_date=";
    this->discharge_date_.Print();
    std::cout << ",doctor=";
    this->doctor_->Print();
    std::cout << ",bed_number=" << this->bed_number_ << ",hospital_charge=" << this->hospital_charge_ << "}";
}