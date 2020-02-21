#include "Reference.hpp"

Reference::Reference()
{
    this->id_ = 0;
    this->author_ = "";
    this->title_ = "";
    this->pubyear_ = 0;
}

Reference::Reference(int id, std::string title, std::string author, int pubyear)
{
    this->id_ = id;
    this->author_ = author;
    this->title_ = title;
    this->pubyear_ = pubyear;
}

const int Reference::GetId() const {
    return this->id_;
}
std::string Reference::GetTitle() {
    return this->title_;
}
void Reference::SetTitle(std::string title) {
    this->title_ = title;
}
std::string Reference::GetAuthor() {
    return this->author_;
}
void Reference::SetAuthor(std::string author) {
    this->author_ = author;
}
int Reference::GetPubYear() {
    return this->pubyear_;
}
void Reference::SetPubYear(int pubyear) {
    this->pubyear_ = pubyear;
}