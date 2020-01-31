#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include "Date.hpp"
class Person
{
    std::string name_;
    Date dob_;
public:
    Person();
    Person(std::string, Date);
    void SetName(std::string);
    std::string GetName();
    void SetDateOfBirth(Date);
    Date GetDateOfBirth();
};
#endif