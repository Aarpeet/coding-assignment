#ifndef CATALOG_H
#define CATALOG_H

#include <map>
#include <string>
#include "Book.h"

class Catalog {
private:
    std::map<int, Book> booklist;

public:
    void addBook(const Book &book);
    Book* searchByName(const std::string &name);
    Book* searchByAuthor(const std::string &author);
    Book* searchById(int id);
};

#endif
