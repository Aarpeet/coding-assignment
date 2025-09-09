#include "Librarian.h"
#include <iostream>

Librarian::Librarian(int id, const std::string& n, const std::string& e, const std::string& p, const std::string& a)
    : User(id, n, e, p, a), isAdmin(true) {}

void Librarian::addBook(Catalog& catalog, const Book& book) {
    catalog.addBook(book);
    std::cout << "Book added: " << book.getTitle() << "\n";
}

void Librarian::removeBook(Catalog& catalog, int bookId) {
    Book* book = catalog.searchById(bookId);
    if (book) {
        book->setAvailability(false);
        std::cout << "Book removed: " << book->getTitle() << "\n";
    }
}

void Librarian::rentBookToUser(User& user, Book& book) {
    user.borrowBook(book);
}

void Librarian::receiveBook(User& user, Book& book) {
    user.returnBook(book);
}
