#include "lab2.hpp"
#include <iostream>
#include <cstdlib>

Book::Book() : author("Неизвестно"), title("Без названия"), pages(0), price(0.0f), rating(0) {}

Book::Book(const std::string& a, const std::string& t, const std::vector<std::string>& w, int p, float pr)
    : author(a), title(t), works(w), pages(p), price(pr), rating(0) {
}




Book::Book(const Book& other)
    : author(other.author), title(other.title), works(other.works), pages(other.pages),
    price(other.price), rating(other.rating) {
}



Book::~Book() {
    std::cout << "Деструктор (книга) " << title << std::endl;
    works.clear();
}




std::string Book::getAuthor() const { return author; }
std::string Book::getTitle() const { return title; }
int Book::getPages() const { return pages; }
float Book::getPrice() const { return price; }
int Book::getRating() const { return rating; }
std::vector<std::string> Book::getWorks() const { return works; }

void Book::setAuthor(const std::string& a) { author = a; }
void Book::setTitle(const std::string& t) { title = t; }
void Book::setPages(int p) { pages = p; }
void Book::setPrice(float pr) { price = pr; }
void Book::setRating(int r) { rating = r; }
void Book::setWorks(const std::vector<std::string>& w) { works = w; }

void Book::changePrice(float x) { price += x; }
void Book::ratePositive() { ++rating; }
void Book::rateNegative() { --rating; }

Book Book::operator+(const Book& other) const {
    Book result;

    if (author == other.author)
        result.author = author;
    else
        result.author = author + " и " + other.author;

    result.title = title + " + " + other.title;
    result.pages = pages + other.pages;
    result.price = (price + other.price) * 0.85f;
    result.rating = 0;

    for (const auto& w : works) {
        std::string item = (author == other.author) ? w : author + w;
        bool found = false;
        for (const auto& existing : result.works) {
            if (item == existing) {
                found = true;
                break;
            }
        }
        if (!found)
            result.works.push_back(item);
    }

    for (const auto& w : other.works) {
        std::string item = (author == other.author) ? w : other.author + w;
        bool found = false;
        for (const auto& existing : result.works) {
            if (item == existing) {
                found = true;
                break;
            }
        }
        if (!found)
            result.works.push_back(item);
    }

    return result;
}

Book& Book::operator+=(const Book& other) {
    if (author == other.author) {
        for (const auto& w : other.works) {
            bool found = false;
            for (const auto& existing : works) {
                if (w == existing) {
                    found = true;
                    break;
                }
            }
            if (!found)
                works.push_back(w);
        }
    }
    else {
        std::vector<std::string> newWorks;
        for (const auto& w : works)
            newWorks.push_back(author + w);
        for (const auto& w : other.works)
            newWorks.push_back(other.author + w);
        works = newWorks;
        author = author + " и " + other.author;
    }

    pages += other.pages;
    price = (price + other.price) * 0.85f;
    title = title + " + " + other.title;

    return *this;
}

Book Book::operator/(const Book& other) const {
    Book result;

    if (author == other.author)
        result.author = author;
    else
        result.author = author + " и " + other.author;

    result.title = "Антология";
    result.pages = static_cast<int>((pages + other.pages) * 0.7f);
    result.price = (price + other.price) * 1.1f;
    result.rating = 0;

    for (const auto& w : works) {
        if (rand() % 2 == 1) {
            std::string item = (author == other.author) ? w : author + w;
            result.works.push_back(item);
        }
    }

    for (const auto& w : other.works) {
        if (rand() % 2 == 1) {
            std::string item = (author == other.author) ? w : other.author + w;
            bool found = false;
            for (const auto& existing : result.works) {
                if (item == existing) {
                    found = true;
                    break;
                }
            }
            if (!found)
                result.works.push_back(item);
        }
    }

    if (result.works.empty() && !works.empty())
        result.works.push_back(author + works[0]);

    return result;
}

void Book::show() const {
    std::cout << "....................." << std::endl;
    std::cout << "Название: " << title << std::endl;
    std::cout << "Автор: " << author << std::endl;
    std::cout << "Страниц: " << pages << std::endl;
    std::cout << "Цена: " << price << " руб." << std::endl;
    std::cout << "Рейтинг: " << rating << std::endl;
    std::cout << "Произведения: ";
    for (size_t i = 0; i < works.size(); ++i) {
        std::cout << works[i];
        if (i != works.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
    std::cout << "_______________________________" << std::endl;
}
