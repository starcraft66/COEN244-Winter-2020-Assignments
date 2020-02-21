#ifndef _REFERENCEMANAGER_H_
#define _REFERENCEMANAGER_H_
#include "Reference.hpp"
#include <array>

class ReferenceManager
{
    Reference* references_;
    int size_, count_;
public:
    ReferenceManager();
    ReferenceManager(int);
    ~ReferenceManager();
    bool Add(Reference&);
    int Get(int);
    bool Delete(int);
    bool Search(int);
};
#endif