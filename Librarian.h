#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"
#include "Catalog.h"
#include "Book.h"

class Librarian : public User {
private:
    bool isAdmin;

public:
    Librarian(int id, const std::string& n, const std::string& e,
              const std::string& p, const std::string& a);

    void addBook(Catalog& catalog, const Book& book);
    void removeBook(Catalog& catalog, int bookId);
    void rentBookToUser(User& user, Book& book);
    void receiveBook(User& user, Book& book);
};

#endif
