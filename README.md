# Library Management System

This is a simple **C++ Library Management System** that demonstrates object-oriented programming with `User`, `Librarian`, `Book`, and `Catalog` classes. The system allows:

- Registering users and librarians  
- Adding books to the catalog  
- Searching, borrowing, and returning books  

The `main.cpp` file includes a **step-by-step demonstration** of these actions with detailed console output.

---

## Files

- `User.h` / `User.cpp` – Defines the `User` class and its actions (borrow, return, search, pay fine).  
- `Librarian.h` / `Librarian.cpp` – Inherits from `User` and adds librarian-specific actions (add/remove books, rent/receive books).  
- `Book.h` / `Book.cpp` – Defines the `Book` class with attributes like title, author, and availability.  
- `Catalog.h` / `Catalog.cpp` – Stores all books and allows searching by ID or name.  
- `main.cpp` – Demonstrates the system with verbose output for every action.

---

## How to Compile

1. Make sure you have a **C++ compiler** installed (like `g++`).  
2. Open a terminal in the project directory.  
3. Compile all `.cpp` files together:

```bash
g++ -std=c++17 main.cpp User.cpp Librarian.cpp Book.cpp Catalog.cpp -o library_system
./library_system
```

## NOTE
The payFine feature works based on ctime, hence can only be demonstrated 