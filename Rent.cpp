#include "Rent.h"
#include <ctime>

Rent::Rent(int bid, int uid, long long due)
    : bookId(bid), userId(uid), dueDate(due) {}

int Rent::getBookId() const {
    return bookId;
}

int Rent::calculateFine() const {
    // Fine logic: 10 currency units per day overdue
    std::time_t now = std::time(nullptr);
    if (now > dueDate) {
        long long daysLate = (now - dueDate) / (60 * 60 * 24);
        return static_cast<int>(daysLate * 10) > 0 ? static_cast<int>(daysLate * 10) : 10;
    }
    return 0;
}
