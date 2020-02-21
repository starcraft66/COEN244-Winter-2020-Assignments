#include "TextBook.hpp"
#include "Article.hpp"
#include "ReferenceManager.hpp"
#include <array>
#include <algorithm>
#include <iostream>

ReferenceManager::ReferenceManager()
{
    this->size_ = 1;
    this->references_ = new Reference[1];
    this->count_ = 0;
}

ReferenceManager::ReferenceManager(int count)
{
    this->size_ = count;
    this->references_ = new Reference[count];
    this->count_ = 0;
}

ReferenceManager::~ReferenceManager()
{
    delete[] this->references_;
}

bool ReferenceManager::Add(Reference& ref)
{
    if (this->size_ == this->count_)
    {
        return false;
    }
    this->references_[this->count_] = ref;
    this->count_++;
    return true;
}   

int ReferenceManager::Get(int id)
{
    return this->references_[id].GetId();
}

bool ReferenceManager::Delete(int id)
{
    if (id < 0 || id >= this->size_)
    {
        return false;
    }
    std::move(&this->references_[id + 1], &this->references_[this->size_], &this->references_[id]);
    this->count_--;
    return true;
}

bool ReferenceManager::Search(int id)
{
    for (int i = 0; i < this->count_; i++)
    {
        if (this->references_[i].GetId() == id)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    ReferenceManager rm = ReferenceManager(500);
    Reference r1 = Reference();
    Reference r2 = Reference(100, "mommy", "mommy", 2222);
    Article a1 = Article();
    Article a2 = Article(666, "mommy", "mommy", 666, "mommy", 666, 666);
    Book b1 = Book();
    Book b2 = Book(456, "mommy", "mommy", 420, 1337, "mommy");
    TextBook tb1 = TextBook();
    TextBook tb2 = TextBook(567, "mommy", "mommy", 345, 666, "mommy", "mommy");
    rm.Add(r1);
    rm.Add(r2);
    rm.Add(a1);
    rm.Add(a2);
    rm.Add(b1);
    rm.Add(b2);
    rm.Add(tb1);
    rm.Add(tb2);
    std::cout << rm.Search(456) << std::endl;
    std::cout << rm.Search(23) << std::endl;
    std::cout << rm.Get(5) << std::endl;
    std::cout << rm.Delete(5) << std::endl;
    std::cout << rm.Get(6) << std::endl;
    return 0;
}