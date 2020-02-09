#include "Date.hpp"
#include <iostream>

Date::Date()
{

}

Date::~Date()
{
    std::cout << "Date object deleted" << std::endl;
}

Date::Date(int day, int month, int year)
{
    this->day_ = day;
    this->month_ = month;
    this->year_ = year;
}

void Date::SetDay(int day)
{
    this->day_ = day;
}

int Date::GetDay()
{
    return this->day_;
}

void Date::SetMonth(int month)
{
    this->month_ = month;
}

int Date::GetMonth()
{
    return this->month_;
}

void Date::SetYear(int year)
{
    this->year_ = year;
}

int Date::GetYear()
{
    return this->year_;
}

bool Date::operator==(const Date& date) const
{
   return date.day_ == this->day_ && date.month_ == this->month_ && date.year_ == this->year_;
}