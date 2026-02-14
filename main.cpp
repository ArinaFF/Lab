#include "lab2.hpp"
#include <iostream>
#include <vector>



int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<std::string> works1 = { "a", "b", "v" };
    std::vector<std::string> works2 = { "a", "m", "n" };



    Book book1a("A", works1, 25, 100.0f);
    Book book2a("A", works2, 50, 100.0f);

    std::cout << " нига 1:" << std::endl;
    book1a.show();

    std::cout << " нига 2:" << std::endl;
    book2a.show();

    std::cout << "–езультат книга 1 + книга 2:" << std::endl;
    Book book21 = book1a + book2a;
    book21.show();

    std::cout << "–езультат книга 1 / книга 2:" << std::endl;
    Book book12 = book1a / book2a;
    book12.show();

    Book book3("B", works2, 50, 100.0f);
    std::cout << "\n нига 3:" << std::endl;
    book3.show();

    std::cout << "–езультат книга 1 + книга 3:" << std::endl;
    Book book13 = book1a + book3;
    book13.show();

    
    return 0;
}