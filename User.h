#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Rent.h"
#include "Catalog.h"
#include "Book.h"

class User {
protected:
    int userId;
    std::string name;
    std::string email;
    std::string phone;
    std::string address;
    std::vector<Rent> rentedBooks;
    static std::vector<User> registeredUsers;

public:
    User(int id, const std::string& n, const std::string& e,
         const std::string& p, const std::string& a);

    void registerUser();
    bool login(const std::string& emailInput, const std::string& phoneInput);
    void searchBook(Catalog& catalog, const std::string& title);
    void borrowBook(Book& book);
    void returnBook(Book& book);
    void payFine(int amount);
};

#endif
