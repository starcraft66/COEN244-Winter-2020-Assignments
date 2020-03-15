#ifndef BED_H_
#define BED_H_
class Bed
{
    int id_;
    bool occupied_;
public:
    Bed();
    Bed(int, bool);
    bool GetOccupied();
    void SetOccupied(bool);
    int GetId();
    void Print();
};
#endif