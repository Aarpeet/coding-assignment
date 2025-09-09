#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    int price;
    bool available;

public:
    Book(int id, const std::string &title, const std::string &author, int price);
    int getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getPrice() const;
    bool getAvailability() const;
    void setAvailability(bool);
};

#endif
