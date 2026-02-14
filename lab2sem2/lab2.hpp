#ifndef LAB_2_H
#define LAB_2_H

#include <string>
#include <vector>


class Book {
public:
    std::string author;
    std::vector<std::string> works;
    int pages;
    float price;

    Book();
    Book(std::string a, std::vector<std::string> w, int p, float pr);

    Book operator+(Book other);
    Book operator/(Book other);

    void show();
};

#endif