#include "Librarian.h"
#include "Catalog.h"
#include "Book.h"
#include "User.h"
#include <iostream>
#include <vector>
#include <memory> // for smart pointers
#include <thread>
#include <chrono>

#define GAP std::cout << endl;

using namespace std;



// Containers for all registered users and librarians
std::vector<std::shared_ptr<User>> allUsers;

// Function to handle registration
void handleRegistration() {
    int choice;
    std::cout << "Register as:\n1. User\n2. Librarian\nChoice: ";
    std::cin >> choice;
    std::cin.ignore(); // flush newline

    int id;
    std::string name, email, phone, address;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter Phone: ";
    std::getline(std::cin, phone);

    std::cout << "Enter Address: ";
    std::getline(std::cin, address);

    if (choice == 1) {
        auto user = std::make_shared<User>(id, name, email, phone, address);
        allUsers.push_back(user);
        std::cout << "User registration successful!\n";
    } else if (choice == 2) {
        auto librarian = std::make_shared<Librarian>(id, name, email, phone, address);
        allUsers.push_back(librarian);
        std::cout << "Librarian registration successful!\n";
    } else {
        std::cout << "Invalid choice!\n";
    }
}

#include "User.h"
#include "Librarian.h"
#include "Catalog.h"
#include "Book.h"
#include <iostream>

int main() {
    std::cout << "Step 1: Creating an empty Catalog to store books." << std::endl;
    Catalog catalog;

    GAP

    std::cout << "Step 2: Registering a Librarian." << std::endl;
    Librarian lib(1, "Admin", "admin@lib.com", "12345", "Library Street");
    std::cout << "Librarian created with ID: " << 1 << ", Name: Admin" << std::endl;

    GAP

    std::cout << "Step 3: Librarian adding books to the catalog." << std::endl;
    Book b1(101, "C++ Basics", "Bjarne", 500);
    Book b2(102, "Clean Code", "Robert", 600);
    std::cout << "Adding book: " << b1.getTitle() << std::endl;
    lib.addBook(catalog, b1);
    std::cout << "Adding book: " << b2.getTitle() << std::endl;
    lib.addBook(catalog, b2);

    GAP

    std::cout << "Step 4: Registering a User." << std::endl;
    User u1(2, "John", "john@gmail.com", "98765", "City Road");
    std::cout << "User created with ID: " << 2 << ", Name: John" << std::endl;

    GAP

    std::cout << "Step 5: User searching for a book titled 'C++ Basics'." << std::endl;
    Book* book = catalog.searchByName("C++ Basics");
    if (book) {
        std::cout << "Book found: " << book->getTitle() << " by " << book->getAuthor() << std::endl;
    } else {
        std::cout << "Book not found in catalog." << std::endl;
    }

    GAP

    std::cout << "Step 6: User borrowing this book(C++ Basics)." << std::endl;
    if (book) {
        lib.rentBookToUser(u1, *book);
        std::cout << "Book status: " << (book->getAvailability() ? "Available" : "Borrowed") << std::endl;
    }

    GAP
    
    std::cout << "Step 7: User searching for a book authored by 'Robert'." << std::endl;
    Book* book2 = catalog.searchByAuthor("Robert");
    if (book) {
        std::cout << "Book found: " << book->getTitle() << " by " << book->getAuthor() << std::endl;
    } else {
        std::cout << "Book not found in catalog." << std::endl;
    }

    GAP

    std::cout << "Step 8: User borrowing the book. (Robert)" << std::endl;
    if (book) {
        lib.rentBookToUser(u1, *book2);
        std::cout << "Book status: " << (book->getAvailability() ? "Available" : "Borrowed") << std::endl;
    }

    GAP
    

    std::cout << "Step 9: User returning the book. (Robert)" << std::endl;
    if (book) {
        lib.receiveBook(u1, *book2);
        std::cout << "Book status: " << (book->getAvailability() ? "Available" : "Borrowed") << std::endl;
    }

    GAP

    std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate

    std::cout << "Step 10: User returning the book." << std::endl;
    if (book) {
        lib.receiveBook(u1, *book);
        std::cout << "Book status: " << (book->getAvailability() ? "Available" : "Borrowed") << std::endl;
    }

    GAP


    std::cout << "All actions completed successfully." << std::endl;

    return 0;
}

