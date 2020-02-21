#include "Book.hpp"
#include <string>

Book::Book()
 : Reference()
{
    this->pages_ = 0;
    this->publisher_ = "";
}

Book::Book(int id, std::string title, std::string author, int pubyear, int pages)
 : Reference(id, title, author, pubyear)
{
    this->pages_ = pages;
    this->publisher_ = "";
}

Book::Book(int id, std::string title, std::string author, int pubyear, int pages, std::string publisher)
 : Reference(id, title, author, pubyear)
{
    this->pages_ = pages;
    this->publisher_ = publisher;
}

int Book::GetNumberOfPages()
{
    return this->pages_;
}

std::string Book::GetPublisher()
{
    return this->publisher_;
}