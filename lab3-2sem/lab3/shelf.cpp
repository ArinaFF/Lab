#include "shelf.h"
#include <iostream>
#include <algorithm>


Bookmark::Bookmark(const std::string& c, const std::string& m, int p)
    : color(c), material(m), pageNum(p) {
}

Bookmark& Bookmark::operator++() {
    ++pageNum;
    return *this;
}


Bookmark& Bookmark::operator--() {
    if (pageNum > 1) --pageNum;
    return *this;
}


void Bookmark::show() const {
    std::cout << "Флажок: цвет = " << color << ", материал = " << material
        << ", стр. " << pageNum << std::endl;
}


Shelf::Shelf(int capacity) : maxCapacity(capacity) {}

Shelf::Shelf(const Shelf& other) : maxCapacity(other.maxCapacity), books(other.books) {}

Shelf::~Shelf() {
    std::cout << "Полка удалена" << std::endl;
}


void Shelf::addBook(Book* book) {
    if (static_cast<int>(books.size()) < maxCapacity) {
        books.push_back(book);
        std::cout << "Книга \"" << book->getTitle() << "\" поставлена на полку." <<std::endl;
    }
    else {
        std::cout << "Полка заполнена!" << std::endl;
    }
}


void Shelf::sortByTitle() {
    for (size_t i = 0; i < books.size(); ++i)
        for (size_t j = 0; j < books.size() - 1; ++j)
            if (books[j]->getTitle() > books[j + 1]->getTitle())
                std::swap(books[j], books[j + 1]);
    std::cout << "Книги отсортированы по названию." << std::endl;
}

void Shelf::show() const {
    std::cout << "=== Полка (вместимость: " << maxCapacity << ") ===" << std::endl;
    std::cout << "Книг на полке: " << books.size() << std::endl;
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << i + 1 << ") ";
        books[i]->show();
    }
  
    std::cout << "......................................" << std::endl;
    std::cout << " " << std::endl;

}
