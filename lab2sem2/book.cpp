#include "lab2.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Book::Book() : author(""), pages(0), price(0.0f) {}

Book::Book(const std::string& a, const std::vector<std::string>& w, int p, float pr)
    : author(a), works(w), pages(p), price(pr) {
}


Book Book::operator+(const Book& other) const {
    Book result;

    
    if (author == other.author) {
        result.author = author;
    }
    else {
        result.author = author + " и " + other.author;
    }

    result.pages = pages + other.pages;
    result.price = (price + other.price) * 0.85f;

    
    for (const auto& work : works) {
        std::string item = (author == other.author) ? work : author + work;
        bool found = false;
        for (const auto& existing : result.works) {
            if (item == existing) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.works.push_back(item);
        }
    }

    
    for (const auto& work : other.works) {
        std::string item = (author == other.author) ? work : other.author + work;
        bool found = false;
        for (const auto& existing : result.works) {
            if (item == existing) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.works.push_back(item);
        }
    }

    return result;
}


Book& Book::operator+=(const Book& other) {
    if (author == other.author) {
        
        for (const auto& work : other.works) {
            bool found = false;
            for (const auto& existing : works) {
                if (work == existing) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                works.push_back(work);
            }
        }
        
    }
    else {
       
        std::vector<std::string> newWorks;
        for (const auto& work : works) {
            newWorks.push_back(author + work);
        }
        for (const auto& work : other.works) {
            newWorks.push_back(other.author + work);
        }
        works = newWorks;
        author = author + " и " + other.author;
    }

    pages += other.pages;
    price = (price + other.price) * 0.85f;

    return *this;
}


Book Book::operator/(const Book& other) const {
    Book result;

    if (author == other.author) {
        result.author = author;
    }
    else {
        result.
            author = author + " и " + other.author;
    }

    result.pages = static_cast<int>((pages + other.pages) * 0.7f);
    result.price = (price + other.price) * 1.1f;

    for (const auto& work : works) {
        if (rand() % 2 == 1) {
            std::string item = (author == other.author) ? work : author + work;
            result.works.push_back(item);
        }
    }

    for (const auto& work : other.works) {
        if (rand() % 2 == 1) {
            std::string item = (author == other.author) ? work : other.author + work;
            bool found = false;
            for (const auto& existing : result.works) {
                if (item == existing) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.works.push_back(item);
            }
        }
    }

    if (result.works.empty() && !works.empty()) {
        result.works.push_back(author + works[0]);
    }

    return result;
}

void Book::show() const {
    std::cout << "....................." << std::endl;
    std::cout << "Автор: " << author << std::endl;
    std::cout << "Страниц: " << pages << std::endl;
    std::cout << "Цена: " << price << " руб." << std::endl;
    std::cout << "Произведения: ";
    for (size_t i = 0; i < works.size(); ++i) {
        std::cout << works[i];
        if (i != works.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    std::cout << "_______________________________" << std::endl;
}
