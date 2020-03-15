#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor()
{
    this->id_ = 0;
    this->medical_license_number_ = "";
    this->name_ = "";
    this->specialty_ = "";
}

Doctor::Doctor(int id, std::string medical_license_number, std::string name, std::string specialty)
{
    this->id_ = id;
    this->medical_license_number_ = medical_license_number;
    this->name_ = name;
    this->specialty_ = specialty;
}

void Doctor::SetName(std::string name)
{
    this->name_ = name;
}

std::string Doctor::GetName()
{
    return this->name_;
}

int Doctor::GetId()
{
    return this->id_;
}

void Doctor::Print()
{
    std::cout << "Doctor{medical_license_number=" << this->medical_license_number_ << ",name=" << this->name_ << ",specialty=" << this->specialty_ << "}";
}