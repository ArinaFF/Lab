#include "lab2.h"
#include "shelf.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void myLabRating() {
    std::cout << "..........................................." << std::endl;
    std::cout << "Моя оценка лабы:" << std::endl;
    std::cout << "Интерес:          9/10" << std::endl;
    std::cout << "Наполненность:    9/10" << std::endl;
    std::cout << "Сложность:        9/10" << std::endl;
    std::cout << "........................................." << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));

   
    std::vector<std::string> works1 = { "a", "b", "v" };
    std::vector<std::string> works2 = { "a", "m", "n" };
    std::vector<std::string> works3 = { "a", "m", "n" };

    Book book1("A", "Сборник первый", works1, 25, 100.0f);
    Book book2("A", "Сборник второй", works2, 50, 100.0f);
    Book book3("B", "Сборник третий", works3, 50, 100.0f);

    std::cout << "========== Книга 1 ==========" << std::endl;
    book1.show();
    std::cout << "========== Книга 2 ==========" << std::endl;
    book2.show();
    std::cout << "========== Книга 3 ==========" << std::endl;
    book3.show();

    
    std::cout << "========== Книга 1 / Книга 2 ==========" << std::endl;
    Book bookDiv = book1 / book2;
    bookDiv.show();   

    
    std::cout << "========== Книга 1 + Книга 2 (одинаковые авторы) ==========" << std::endl;
    Book bookSum1 = book1 + book2;
    bookSum1.show();

    std::cout << "========== Книга 1 + Книга 3 (разные авторы) ==========" << std::endl;
    Book bookSum2 = book1 + book3;
    bookSum2.show();

    
    std::cout << "========== Книга 1 += Книга 2 ==========" << std::endl;
    book1 += book2;   
    book1.show();

    std::cout <<" " << std::endl;
    std::cout << "========== Изменение цены и рейтинг ==========" << std::endl;
    book3.changePrice(20.0f);
    std::cout << "Цена книги 3 после увеличения на 20: " << book3.getPrice() << " руб." << std::endl;

    book3.ratePositive();
    book3.ratePositive();
    book3.rateNegative();
    std::cout << "Рейтинг книги 3 после двух + и одного -: " << book3.getRating() << std::endl;

    
    std::cout << "========== Флажок ==========" << std::endl;
    Bookmark bm("красный", "Картон", 21);
    std::cout << "Создан флажок: " <<std::endl;
    bm.show();

    ++bm;
    std::cout << "После ++: ";
    bm.show();

    --bm;
    std::cout << "После --: ";
    bm.show();

    
    std::cout << "========== Полка ==========" << std::endl;
    Shelf shelf(5);
    shelf.addBook(&book1);
    shelf.addBook(&book2);
    shelf.addBook(&book3);
    shelf.addBook(&bookSum1);
    shelf.addBook(&bookSum2);
    shelf.show();

    std::cout << "------ Сортировка по названию -------" << std::endl;
    shelf.sortByTitle();
    shelf.show();

    
    myLabRating();

    return 0;
}
