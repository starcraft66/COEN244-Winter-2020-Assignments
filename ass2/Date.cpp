#include "Date.hpp"

Date::Date()
{

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

void Date::SetMonth(int month)
{
    this->month_ = month;
}

void Date::SetYear(int year)
{
    this->year_ = year;
}
