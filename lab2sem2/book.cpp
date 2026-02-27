#include "lab2.hpp"
#include <iostream>



Book::Book() {
	author = "";
	pages = 0;
	price = 0;
	works = {};

}
Book::Book(std::string a, std::vector<std::string> w, int p, float pr) {
	author = a;
	pages = p;
	price = pr;
	works = w;
}

Book Book::operator+(Book other) {
	Book result;


	if (author == other.author) {
		result.author = author;
	}
		
	else {
		result.author = author + " и " + other.author;
	}

	
	result.pages = pages + other.pages;
	result.price = (price + other.price) * 0.85f;
	result.works = works;


	for (int i = 0; i < other.works.size(); i++) {
		bool find = false;
		for (int j = 0; j < works.size(); j++) {
			if (other.works[i] == works[j]) {
				find = true;
				break;
			}
		}
		if (!find) {
			result.works.push_back(other.works[i]);
		}
	}
	return result;

}



Book Book::operator+=(Book other) {

	pages = pages + other.pages;

	price = (price + other.price) * 0.85f;

	std::vector<std::string> newwork;

	for (int i = 0; i < works.size(); i++) {
		newwork.push_back(author + works[i]);
	}
	for (int i = 0; i < other.works.size(); i++) {
		newwork.push_back(other.author + other.works[i]);
	}

	works = newwork;

	return *this;
}



Book Book::operator/(Book other) {
	Book result;
	if (author == other.author) {
		result.author = author;
	}
    
	else {
		result.author = author + "и" + other.author;
	}


	
	result.pages = (pages + other.pages) * 0.7f;
	result.price = (price + other.price) * 1.1f;
	srand(time(0));


	for (int i = 0; i < works.size(); i++) {
		int r_index = rand() % 2;
		if (r_index == 1) {
			result.works.push_back(works[i]);
		}
	}


	for (int i = 0; i < other.works.size(); i++) {
		int r_index = rand() % 2;
		if (r_index == 1) {
			bool find = false;

			for (int j = 0; j < result.works.size(); j++) {
				if (other.works[i] == result.works[j]) {
					find = true;
					break;
				}
			}
			if (!find) {
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



void Book::show() {
	setlocale(LC_ALL, "Russian");
	std::cout << "....................." << std::endl;
	std::cout << "Автор: " << author << std::endl;
	std::cout << "Страниц в книге: " << pages << std::endl;
	std::cout << "Цена: " << price << " руб. " << std::endl;
	std::cout << "Произведения: ";
	for (int i = 0; i < works.size(); i++) {
		std::cout << works[i];
		if (i != works.size() - 1) {
			std::cout << " , ";
		}
	}

	std::cout << std::endl;
	std::cout << "_______________________________" << std::endl;
}
