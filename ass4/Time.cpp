#include "Time.hpp"
#include <iostream>

Time::Time()
{
    this->hour_ = 0;
    this->minute_ = 0;
    this->second_ = 0;
}


Time::Time(int hour, int minute, int second)
{
    this->hour_ = hour;
    this->minute_ = minute;
    this->second_ = second;
}

void Time::Print()
{
    std::cout << "Time{hour=" << this->hour_ << ",minute=" << this->minute_ << ",second=" << this->second_ << "}";
}