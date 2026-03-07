#ifndef SHELF_H
#define SHELF_H

#include "lab2.h"
#include <vector>
#include <string>


struct Bookmark {
    std::string color;
    std::string material;
    int pageNum;

    Bookmark(const std::string& c = "Красный", const std::string& m = "Бумага", int p = 1);
    Bookmark& operator++();
    Bookmark& operator--();
    void show() const;
};


class Shelf {
private:
    std::vector<Book*> books;
    int maxCapacity;
public:
    Shelf(int capacity = 10);
    Shelf(const Shelf& other);
    ~Shelf();

    void addBook(Book* book);
    void sortByTitle();   
    void show() const;
};

#endif
