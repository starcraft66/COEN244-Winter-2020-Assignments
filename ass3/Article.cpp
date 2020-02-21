#include "Article.hpp"

Article::Article()
 : Reference()
{
    this->journal_ = "";
    this->startpage_ = 0;
    this->endpage_ = 0;
}

Article::Article(int id, std::string title, std::string author, int pubyear, std::string journal, int startpage, int endpage)
 : Reference(id, title, author, pubyear)
{
    this->journal_ = journal;
    this->startpage_ = startpage;
    this->endpage_ = endpage;
}

int Article::GetNumberOfPages() const
{
    return this->endpage_ - this->startpage_;
}