#include "User.h"
#include <iostream>
#include <ctime>

#define RENTAL_TIME 1 // 7 days in seconds

User::User(int id, const std::string& n, const std::string& e,
           const std::string& p, const std::string& a)
    : userId(id), name(n), email(e), phone(p), address(a) {}

void User::registerUser() {
    // std::cout << "Enter User ID: ";
    // std::cin >> userId;
    // std::cin.ignore(); // ignore leftover newline

    // std::cout << "Enter Name: ";
    // std::getline(std::cin, name);

    // std::cout << "Enter Email: ";
    // std::getline(std::cin, email);

    // std::cout << "Enter Phone: ";
    // std::getline(std::cin, phone);

    // std::cout << "Enter Address: ";
    // std::getline(std::cin, address);

    // // Save this user in the static vector
    // registeredUsers.push_back(*this);

    // std::cout << "Registration successful!\n";
}

bool User::login(const std::string& emailInput, const std::string& phoneInput) {
    // for (const auto& user : registeredUsers) {
    //     if (user.email == emailInput && user.phone == phoneInput) {
    //         std::cout << "Login successful! Welcome " << user.name << "\n";
    //         return true;
    //     }
    // }
    // std::cout << "Login failed! Invalid email or phone.\n";
    // return false;

    return true;
}

void User::searchBook(Catalog& catalog, const std::string& title) {
    Book* book = catalog.searchByName(title);
    if (book)
        std::cout << "Book found: " << book->getTitle() << "\n";
    else
        std::cout << "Book not found\n";
}

void User::borrowBook(Book& book) {
    if (book.getAvailability()) {
        book.setAvailability(false);
        std::time_t dueDate = std::time(nullptr) + RENTAL_TIME;
        rentedBooks.emplace_back(book.getBookId(), userId, dueDate);
        std::cout << "Book borrowed: " << book.getTitle() << "\n";
    } else {
        std::cout << "Book not available\n";
    }
}

void User::returnBook(Book& book) {
    for (auto it = rentedBooks.begin(); it != rentedBooks.end(); ++it) {
        if (it->getBookId() == book.getBookId()) {
            int fine = it->calculateFine();
            if (fine > 0) {
                std::cout << "Please pay fine: " << fine << "\n";
            }
            rentedBooks.erase(it);
            book.setAvailability(true);
            std::cout << "Book returned: " << book.getTitle() << "\n";
            return;
        }
    }
    std::cout << "This book was not borrowed by this user.\n";
}

void User::payFine(int amount) {
    std::cout << "Fine paid: " << amount << "\n";
}
