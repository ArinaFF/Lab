#include "lab2.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

    std::cout << "========== Книга 1 + Книга 2 (одинаковые авторы) ==========" << std::endl;
    Book book4 = book1 + book2;
    book4.show();

    std::cout << "========== Книга 1 + Книга 3 (разные авторы) ==========" << std::endl;
    Book book5 = book1 + book3;
    book5.show();

    std::cout << "========== Книга 1 += Книга 2 ==========" << std::endl;
    book1 += book2;
    book1.show();

    std::cout << "========== Книга 1 / Книга 2 ==========" << std::endl;
    Book book6 = book1 / book2;
    book6.show();

    std::cout << "========== Демонстрация методов изменения ==========" << std::endl;
    book3.changePrice(20.0f);
    std::cout << "Цена книги 3 после увеличения на 20: " << book3.getPrice() << " руб." << std::endl;

    book3.ratePositive();
    book3.ratePositive();
    book3.rateNegative();
    std::cout << "Рейтинг книги 3 после двух + и одного -: " << book3.getRating() << std::endl;

    return 0;
}
