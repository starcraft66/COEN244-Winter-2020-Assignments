#ifndef TIME_H_
#define TIME_H_
class Time
{
    int hour_;
    int minute_;
    int second_;
public:
    Time();
    Time(int, int, int);
    void Print();
};
#endif