#include "Catalog.h"

void Catalog::addBook(const Book &book) {
    booklist.emplace(book.getBookId(), book);
}

Book* Catalog::searchByName(const std::string &name) {
    for (auto &pair : booklist) {
        if (pair.second.getTitle() == name) return &pair.second;
    }
    return nullptr;
}

Book* Catalog::searchByAuthor(const std::string &author) {
    for (auto &pair : booklist) {
        if (pair.second.getAuthor() == author) return &pair.second;
    }
    return nullptr;
}

Book* Catalog::searchById(int id) {
    auto it = booklist.find(id);
    if (it != booklist.end()) return &it->second;
    return nullptr;
}
