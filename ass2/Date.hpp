#ifndef DATE_H_
#define DATE_H_
class Date
{
    int day_;
    int month_;
    int year_;
public:
    Date();
    Date(int, int, int);
    void SetDay(int);
    int GetDay();
    void SetMonth(int);
    int GetMonth(); 
    void SetYear(int);
    int GetYear();
};
#endif