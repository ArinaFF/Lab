#ifndef LAB_2_HPP
#define LAB_2_HPP

#include <string>
#include <vector>

class Book {
public:
    std::string author;
    std::vector<std::string> works;
    int pages;
    float price;

    Book();
    Book(const std::string& a, const std::vector<std::string>& w, int p, float pr);

    Book operator+(const Book& other) const;
    Book operator/(const Book& other) const;
    Book& operator+=(const Book& other);  

    void show() const;
};

#endif
