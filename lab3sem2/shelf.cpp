#include "shelf.h"
#include <iostream>


Shelf::Shelf() {
    maxCapacity = 10;
}

Shelf::Shelf(int capacity) {
    maxCapacity = capacity;
}

Shelf::Shelf(const Shelf& other) {
    maxCapacity = other.maxCapacity;
    books = other.books;
}

Shelf::~Shelf() {
    std::cout << "Полка удалена" << std::endl;
    books.clear();
}

void Shelf::addBook(Book* book) {
    if (books.size() < maxCapacity) {
        books.push_back(book);
        std::cout << "Книга \"" << book->getTitle() << "\" поставлена на полку." << std::endl;
    }

    else {
        std::cout << "Полка заполнена!" << std::endl;
    }
}


void Shelf::sortByTitle() {
    for (int i = 0; i < books.size(); i++) {
        for (int j = 0; j < books.size() - 1; j++) {
            if (books[j]->getTitle() > books[j + 1]->getTitle()) {
                Book* temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    std::cout << "Книги отсортированы по названию." << std::endl;
}


void Shelf::show() {
    std::cout << "=== Полка (вместимость: " << maxCapacity << ") ===" << std::endl;
    std::cout << "Книг на полке: " << books.size() << std::endl;
    for (int i = 0; i < books.size(); i++) {
        std::cout << i + 1 << ") ";
        books[i]->show();
    }
    std::cout << "......................................" << std::endl;
}