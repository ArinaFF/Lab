#include <iostream>
#include <bitset>
//пункт 1. возможны ошибки
int main()
{
	setlocale(LC_ALL, "Russian");// для перевода на русский язык
	short A, i, a;
	short short_b = sizeof(short) * 8; //умножить на 8 чтобы перевести в бит. размер short

	std::cout << " Enter A" << std::endl;
	std::cin >> A;
	std::cout << " Enter i" << std::endl;
	std::cin >> i;
	a = A; // это сделано чтобы сохранить исходное значение А

	if (i >= 0 && i < short_b) { //проверка i
	}

	else {
		std::cout << " не правильное значение i";
		return 0;
	}


	short value_i = A & (1 << i); //сдвиг влево на значение i бит
	if (value_i == 0) {
		A = A * A;
		A = A & ~(1 << i); // установка i бит результата в 0
		std::cout << "A = " << std::bitset<8>(a) << std::endl; //до
		std::cout << "A = " << std::bitset<8>(A) << std::endl; // после
	}
	else {
		short a1 = 125 & 0b10101010; //  заменяю четные биты числа 125 на 0
		std::cout << " 125 => " << a1 << " = " << std::bitset<8>(a1) << std::endl;
		return 0;
	}

	//пункт 2


	std::cout << "введите номер маршрута :";  // просим пользователя ввести номер маршрут
	int N;
	std::cin >> N;
	switch (N) {
	case 113: // номер маршрута и сам маршрут
		std::cout << "  Калининград - Чапаево";
		break;
	case 114:
		std::cout << "Калининград - Зеленоградск";
		break;
	case 117:
		std::cout << "Калининград - Мамоново";
		break;
	case 118:
		std::cout << "Калининград - Светлогорск";
		break;
	case 119:
		std::cout << "Калининград - Пионерский;
		break;
	case 125:
		std::cout << "Калининград - Донское";
		break;
	case 136:
		std::cout << "Калининград - Партизанское";
		break;
	case 141:
		std::cout << "Калининград - Зеленоградск";
		break;
	case 148:
		std::cout << "Калининград - Багратионовск";
		break;
	case 161:
		std::cout << "Калининград - Светлое";
		break;
	case 191:
		std::cout << "Калининград - Багратионовск";
		break;
	case 593:
		std::cout << "Калининград - Морское";
		break;
	case 802:
		std::cout << "Калининград - Гданьск";
		break;
	default: std::cout << "Неизвестный маршрут"; // вывод при ошибочном номере маршрута

	}
	return 0;


	}

