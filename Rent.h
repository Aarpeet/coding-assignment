#ifndef RENT_H
#define RENT_H

class Rent {
private:
    int bookId;
    int userId;
    long long dueDate;   // store due date as epoch time

public:
    Rent(int bookId, int userId, long long dueDate);

    int getBookId() const;
    int calculateFine() const;
};

#endif
