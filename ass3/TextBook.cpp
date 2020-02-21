#include "TextBook.hpp"

TextBook::TextBook()
 : Book()
{
    this->url_ = "";
}

TextBook::TextBook(int id, std::string title, std::string author, int pubyear, int pages, std::string publisher, std::string url)
 : Book(id, title, author, pubyear, pages, publisher)
{
    this->url_ = url;
}

std::string TextBook::GetURL()
{
    return this->url_;
}

void TextBook::SetURL(std::string url)
{
    this->url_ = url;
}