#include <string>
#include <iostream>
#include "Person.hpp"

Person::Person()
{

}

Person::~Person()
{
    std::cout << "Person " << this->name_ << " deleted" << std::endl;
}

Person::Person(std::string name, Date dob)
{
    this->name_ = name;
    this->dob_ = dob;
}

std::string Person::GetName()
{
    return this->name_;
}

void Person::SetName(std::string name)
{
    this->name_ = name;
}

Date Person::GetDateOfBirth()
{
    return this->dob_;
}

void Person::SetDateOfBirth(Date dob)
{
    this->dob_ = dob;
}

bool Person::operator==(const Person& person) const
{
   return person.name_ == this->name_ && person.dob_ == this->dob_;
}

void Person::Print()
{
    std::cout << "Person: " << this->GetName() << ", born on " << this->GetDateOfBirth().GetDay() << "/" << this->GetDateOfBirth().GetMonth() << "/" << this->GetDateOfBirth().GetYear() << std::endl;
}