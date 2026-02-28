#include "book.h"
#include "shelf.h"
#include <iostream>
#include <vector>



void myLabRating() {
    std::cout << "..........................................." << std::endl;
    std::cout << "Моя оценка лабы:" << std::endl;
    std::cout << "Интерес:          9/10" << std::endl;
    std::cout << "Наполненность:    8/10" << std::endl;
    std::cout << "Сложность:        9/10" << std::endl;
    std::cout << "........................................." << std::endl;
}


int main() {
   
    setlocale(LC_ALL, "Russian");

    std::vector<std::string> works1 = { "Рассказ А", "Рассказ Б", "Рассказ В" };
    std::vector<std::string> works2 = { "Рассказ А", "Рассказ М", "Рассказ Н" };
    std::vector<std::string> works3 = { "Сказка 1", "Сказка 2" };


    Book book1("Автор А", "Сборник первый", works1, 250, 300.0f);
    Book book2("Автор А", "Сборник второй", works2, 180, 250.0f);
    Book book3("Автор Б", "Сборник сказок", works3, 120, 150.0f);


    std::cout << "======= книга 1 =========" << std::endl;
    book1.show();


    std::cout << "======= книга 2 ========" << std::endl;
    book2.show();


    std::cout << "======= книга 3 ========" << std::endl;
    book3.show();


    std::cout << "Автор книги 1: " << book1.getAuthor() << std::endl;
    std::cout << "Цена книги 2: " << book2.getPrice() << std::endl;


    book1.setPrice(350.0f);
    std::cout << "Новая цена 1: " << book1.getPrice() << std::endl;


    book2.changePrice(50.0f);
    std::cout << "Цена книги 2 после изменения на +50: " << book2.getPrice() << std::endl;


    book1.ratePositive();
    book1.ratePositive();
    book1.rateNegative();
    std::cout << "Рейтинг книги 1: " << book1.getRating() << std::endl;


    book1.setBookmark("Синий", "Картон", 21);
    std::cout << "========= Книга 1 с флажком ========" << std::endl;
    book1.show();


    ++book1.bookmark;
   std::cout << "Флажок после ++: стр. " << book1.bookmark.pageNum << std::endl;
    --book1.bookmark;
    std::cout << "Флажок после --: стр. " << book1.bookmark.pageNum << std::endl;


    std::cout << "=========== книга 1 + книга 2 =======" << std::endl;
    Book book4 = book1 + book2;
    book4.show();


    std::cout << "========== книга 1 += книга 2 =======" << std::endl;
    book1 += book2;
    book1.show();


    std::cout << "========== книга 2 / книга 3 ========" << std::endl;
    Book book5 = book2 / book3;
    book5.show();


    std::cout << "======== Копия книги 3 ========" << std::endl;
    Book book6 = book3;
    book6.show();


    std::cout << "---------- Полка ------------" << std::endl;
    Shelf shelf(5);

    shelf.addBook(&book2);
    shelf.addBook(&book3);
    shelf.addBook(&book4);
    shelf.addBook(&book1);

    shelf.show();



    std::cout << "................После сортировки................" << std::endl;
    shelf.sortByTitle();
    shelf.show();

    myLabRating();

    return 0;
}
