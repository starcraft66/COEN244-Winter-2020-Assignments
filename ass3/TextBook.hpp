#ifndef _TEXTBOOK_H_
#define _TEXTBOOK_H_
#include "Book.hpp"

class TextBook : public Book
{
    std::string url_;
public:
    TextBook();
    TextBook(int, std::string, std::string, int, int, std::string, std::string);
    std::string GetURL();
    void SetURL(std::string);
};
#endif