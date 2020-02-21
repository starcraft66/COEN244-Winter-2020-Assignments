#ifndef _BOOK_H_
#define _BOOK_H_
#include "Reference.hpp"

class Book : public Reference
{
    std::string publisher_;
    int pages_;
public:
    Book();
    Book(int, std::string, std::string, int, int);
    Book(int, std::string, std::string, int, int, std::string);
    int GetNumberOfPages();
    std::string GetPublisher();
};
#endif