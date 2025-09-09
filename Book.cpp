#include "Book.h"

Book::Book(int id, const std::string &title, const std::string &author, int price)
    : id(id), title(title), author(author), price(price), available(true) {}

int Book::getBookId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getPrice() const { return price; }
bool Book::getAvailability() const { return available; }
void Book::setAvailability(bool a) { available = a; }
