#ifndef _REFERENCE_H_
#define _REFERENCE_H_
#include <string>

class Reference
{
protected:
    int id_;
    std::string title_;
    std::string author_;
    int pubyear_;

public:
    Reference();
    Reference(int, std::string, std::string, int);
    const int GetId() const;
    void SetTitle(std::string);
    std::string GetTitle();
    void SetAuthor(std::string);
    std::string GetAuthor();
    void SetPubYear(int);
    int GetPubYear();
};
#endif