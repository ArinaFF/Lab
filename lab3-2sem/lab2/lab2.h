#ifndef LAB2_H
#define LAB2_H

#include <string>
#include <vector>

class Book {
public:
    std::string author;
    std::string title;
    std::vector<std::string> works;
    int pages;
    float price;
    int rating;

    Book();
    Book(const std::string& a, const std::string& t, const std::vector<std::string>& w, int p, float pr);
    Book(const Book& other);
    ~Book();

    std::string getAuthor() const;
    std::string getTitle() const;
    int getPages() const;
    float getPrice() const;
    int getRating() const;
    std::vector<std::string> getWorks() const;

    void setAuthor(const std::string& a);
    void setTitle(const std::string& t);
    void setPages(int p);
    void setPrice(float pr);
    void setRating(int r);
    void setWorks(const std::vector<std::string>& w);

    void changePrice(float x);
    void ratePositive();
    void rateNegative();

    Book operator+(const Book& other) const;
    Book operator/(const Book& other) const;
    Book& operator+=(const Book& other);

    void show() const;
};

#endif
