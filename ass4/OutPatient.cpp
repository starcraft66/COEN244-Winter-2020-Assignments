#include "OutPatient.hpp"
#include <iostream>

OutPatient::OutPatient(int id, std::string name, Date appointment_date, Time appointment_time, double hospital_charge, Doctor* doctor)
{
    this->id_ = id;
    this->name_ = name;
    this->appointment_date_ = appointment_date;
    this->appointment_time_ = appointment_time;
    this->hospital_charge_ = hospital_charge;
    this->doctor_ = doctor;
}

void OutPatient::SetName(std::string name)
{
    this->name_ = name;
}

std::string OutPatient::GetName()
{
    return this->name_;
}

int OutPatient::GetId()
{
    return this->id_;
}

void OutPatient::Print()
{
    std::cout << "OutPatient{id=" << this->id_ << ",name=" << this->name_ << ",appointment_date=";
    this->appointment_date_.Print();
    std::cout << ",appointment_time=";
    this->appointment_time_.Print();
    std::cout << ",hospital_charge=" << this->hospital_charge_ << ",doctor=";
    this->doctor_->Print();
    std::cout << "}";
}