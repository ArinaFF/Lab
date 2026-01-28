#include <iostream>
#include <string>

class Book {
private:
	std::string author;
	std::string name;
	int pages;
	float score;
	float price;
	void vscore() {
		if (score > 5.0) {
			score = 5.0;
		}
		if (score < 0.0) {
			score = 0.0;}
	}
	void vprice() {
		if (price < 0) {
			price = 0;
		}
	}


public:
	Book() {
		author = "unknown";
		name = "unknow";
		pages = 0;
		score = 0.0;
		price = 0.0;
	}
	Book(std::string a, std::string n, int p, float s, float pr) {
		author = a;
		name = n;
		pages = p;
		score = s;
		price = pr;
		vscore();
	}

	Book(const Book& other) {
		author = other.author;
		name = other.name;
		pages = other.pages;
		score = other.score;
		price = other.price;
	}

	~Book() {
		std::cout << "Destructor" << std::endl;
	}
	std::string getauthor() {
		return author;
	}
	std::string getname() {
		return name;
	}
	int getpages() {
		return pages;
	}
	float getscore() {
		return score;
	}
	float getprice() {
		return price;
	}

	void setscore(float s) {
		score = s;
		vscore();
		std::cout << "Книга: " << name << ". Оценка была изменена на " << score << std::endl;

	}

	void newprice(float nprice) {
		if (nprice >= 0) {
			price = nprice;
			std::cout<< "Книга: " << name << ". Цена была изменена на " << price << std::endl;
		}
		else {
			std::cout << "Ошибка! Цена не может быть отрицательной." << std::endl;
		}
	}

	void info() {
		std::cout << "    " << std::endl;
		std::cout<< "_____Карта книги____" << std::endl;
		std::cout << "Название :" << name << std::endl;
		std::cout << "Автор: " << author << std::endl;
		std::cout << "Количество страниц: " << pages << std::endl;
		std::cout << "Рейтинг книги: " << score << std::endl;
		std::cout << "Цена: " << price << std::endl;
		std::cout << "        " << std::endl;
	}
};






int main() {
	setlocale(LC_ALL, "Russian");

	Book book1("А.П. Чехов", "Чайка", 288, 4.8, 470);
	book1.info();
	std::cout << "         " << std::endl;
	Book book2 = book1;
	book2.setscore(7.0);
	book2.newprice(500.0);
	book2.info();
	std::cout << "    " << std::endl;
	return 0;

	
}