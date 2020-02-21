#ifndef _ARTICLE_H_
#define _ARTICLE_H_
#include "Reference.hpp"

class Article : public Reference
{
protected:
    std::string journal_;
    int startpage_;
    int endpage_;
public:
    Article();
    Article(int, std::string, std::string, int, std::string, int, int);
    int GetNumberOfPages() const;
    std::string GetPublisher() const;
};
#endif