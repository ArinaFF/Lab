#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include <iostream>


class Book {
public:
    std::string author;
    std::string title;
    std::vector<std::string> works;
    int pages;
    float price;
    int rating;


    struct Bookmark {
        std::string color;
        std::string material;
        int pageNum;


        Bookmark() {
            color = "Красный";
            material = "Бумага";
            pageNum = 1;
        }

        Bookmark(std::string c, std::string m, int p) {
            color = c;
            material = m;
            pageNum = p;
        }

        Bookmark operator++() {
            pageNum = pageNum + 1;
            return *this;
        }

        Bookmark operator--() {
            pageNum = pageNum - 1;
            return *this;
        }

        void show() {
            std::cout << "Флажок: цвет = " << color << ", материал = " << material << ", стр. " << pageNum << std::endl;
        }
    };


    bool hasBookmark;
    Bookmark bookmark;


    Book();
    Book(std::string a, std::string t, std::vector<std::string> w, int p, float pr);
    Book( const Book& other);

    ~Book();

    std::string getAuthor();
    std::string getTitle();
    int getPages();
    float getPrice();
    int getRating();
    std::vector<std::string> getWorks();



    void setAuthor(std::string a);
    void setTitle(std::string t);
    void setPages(int p);
    void setPrice(float pr);
    void setRating(int r);
    void setWorks(std::vector<std::string> w);



    void changePrice(float x);
    void ratePositive();
    void rateNegative();
    void setBookmark(std::string color, std::string material, int page);
    void show();



    Book operator+(Book other);
    Book operator+=(Book other);
    Book operator/(Book other);
};


#endif
