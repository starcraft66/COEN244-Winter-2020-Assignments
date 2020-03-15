#ifndef PERSON_H_
#define PERSON_H_
#include <string>
class Person
{
public:
    virtual std::string GetName() = 0;
    virtual void SetName(std::string) = 0;
    virtual void Print() = 0;
};
#endif