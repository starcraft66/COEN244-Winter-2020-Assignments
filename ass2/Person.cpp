#include <string>
#include "Person.hpp"

Person::Person()
{

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