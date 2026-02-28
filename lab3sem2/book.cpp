#include "book.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Book::Book() {
    
    author = "Неизвестно";
    title = "Без названия";
    works = {};
    pages = 0;
    price = 0;
    rating = 0;
    hasBookmark = false;
}

Book::Book(std::string a, std::string t, std::vector<std::string> w, int p, float pr) {
    author = a;
    title = t;
    works = w;
    pages = p;
    price = pr;
    rating = 0;
    hasBookmark = false;
}

Book::Book(const Book& other) {
    author = other.author;
    title = other.title;
    works = other.works;
    pages = other.pages;
    price = other.price;
    rating = other.rating;
    hasBookmark = other.hasBookmark;
    bookmark = other.bookmark;
}



Book::~Book() {
    std::cout << "Деструктор (книга) " << title << std::endl;
    works.clear();
}


std::string Book::getAuthor() {
    return author;
}

std::string Book::getTitle() {
    return title;
}

int Book::getPages() {
    return pages;
}
float Book::getPrice() {
    return price;
}

int Book::getRating() {
    return rating;
}

std::vector<std::string> Book::getWorks() {
    return works;
}

void Book::setAuthor(std::string a) {
    author = a;
}

void Book::setTitle(std::string t) {
    title = t;
}

void Book::setPages(int p) {
    pages = p;
}

void Book::setPrice(float pr) {
    price = pr;
}

void Book::setRating(int r) {
    rating = r;
}
void Book::setWorks(std::vector<std::string> w) {
    works = w;
}

void Book::changePrice(float x) {
    price = price + x;
}

void Book::ratePositive() {
    rating = rating + 1;
}

void Book::rateNegative() {
    rating = rating - 1;
}

void Book::setBookmark(std::string color, std::string material, int page) {
    hasBookmark = true;
    bookmark = Bookmark(color, material, page);
}

void Book::show() {

    std::cout << "Название книги: " << title << std::endl;
    std::cout << "Автор книги: " << author << std::endl;
    std::cout << "Количество страниц: " << pages << std::endl;
    std::cout << "Цена: " << price << " руб." << std::endl;
    std::cout << "Оценка: " << rating << std::endl;
    std::cout << "Произведения: ";
    for (int i = 0; i < works.size(); i++) {
        std::cout << works[i];
        if (i != works.size() - 1) {
            std::cout << ", ";
        }
    }


    std::cout << std::endl;
    if (hasBookmark == true) {
        bookmark.show();
    }
    else {
        std::cout << "Флажок: нет" << std::endl;
    }
    std::cout << "______________________________________________________________" << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
}



Book Book::operator+(Book other) {
    Book result;

    if (author == other.author) {
        result.author = author;
    }
    else {
        result.author = author + " и " + other.author;
    }

    result.title = title + " + " + other.title;
    result.pages = pages + other.pages;
    result.price = (price + other.price) * 0.85f;
    result.works = works;



    for (int i = 0; i < other.works.size(); i++) {
        bool found = false;
        for (int j = 0; j < result.works.size(); j++) {
            if (other.works[i] == result.works[j]) {
                found = true;
                break;
            }
        }
        if (found == false) {
            result.works.push_back(other.works[i]);
        }
    }

    return result;
}



Book Book::operator+=(Book other) {
    pages = pages + other.pages;
    price = (price + other.price) * 0.85f;

    std::vector<std::string> newWorks;

    for (int i = 0; i < works.size(); i++) {
        newWorks.push_back(author + ": " + works[i]);
    }
    for (int i = 0; i < other.works.size(); i++) {
        newWorks.push_back(other.author + ": " + other.works[i]);
    }

    works = newWorks;

    return *this;
}



Book Book::operator/(Book other) {
    Book result;

    if (author == other.author) {
        result.author = author;
    }
    else {
        result.author = author + " и " + other.author;
    }

    result.title = "Антология";
    result.pages = (int)((pages + other.pages) * 0.7f);
    result.price = (price + other.price) * 1.1f;

    srand(time(0));

    for (int i = 0; i < works.size(); i++) {
        int randomIndex = rand() % 2;
        if (randomIndex == 1) {
            result.works.push_back(works[i]);
        }
    }

    for (int i = 0; i < other.works.size(); i++) {
        int randomIndex = rand() % 2;
        if (randomIndex == 1) {
            bool found = false;
            for (int j = 0; j < result.works.size(); j++) {
                if (other.works[i] == result.works[j]) {
                    found = true;
                    break;
                }
            }
            if (found == false) {
                result.works.push_back(other.works[i]);
            }
        }
    }

    if (result.works.size() == 0) {
        if (works.size() > 0) {
            result.works.push_back(works[0]);
        }
    }

    return result;
}
