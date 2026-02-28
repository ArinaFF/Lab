#ifndef SHELF_H
#define SHELF_H

#include "book.h"
#include <vector>
#include <iostream>

class Shelf {
public:
    std::vector<Book*> books;
    int maxCapacity;

    Shelf();

    Shelf(int capacity);

    Shelf(const Shelf& other);

    ~Shelf();

    void addBook(Book* book);

    void sortByTitle();

    void show();
};

#endif