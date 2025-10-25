#include <iostream>
#include <limits>

int main() {

	// пункт 1
	setlocale(LC_ALL, "Russian");

	const int l = 9; // размер массива
	int arr[l]; //массив

	std::cout << "Введите " << l << " чисeл: ";
	for (int i = 0; i < l; ++i) {
		std::cin >> arr[i];

	}
	bool a = 0;
	for (int i = 0; i < l; ++i) {
		int num = abs(arr[i]); // массив не может быть отриц. ставим модуль
		int d = 0;
		while (num != 0) {
			d = num % 10;
			num /= 10;
		}
		if (d == 3) { // смотрим, есть ли числа с 3
		a = 1;
		break;
		}

	}
	if (a) {
		for (int i = 0; i < l - 1; ++i) {
			for (int j = i + 1; j < l; ++j) {
				for (int k = 0; k < l; ++k) {
				}
				int left = arr[i];
				int r = arr[j];
				if (r < left) {
				arr[i] = r; // массив идет по возрастанию
				arr[j] = left;
				}
			}
		}
		for (int k = 0; k < l; ++k) {
			std::cout << arr[k] << "   ";
		}
	}
	else {
		std::cout << " нет чисел, которое бы начиналось с цифры 3" << std::endl;
	}
	std::cout << std::endl;



		//пункт 2
		int maxim_sum;
		int row;
		bool f_sum = 1;

		const int r = 3;
		const int c = 4;
		int matrix[r][c];

		for (int i = 0; i < r; ++i) { //строки
		std::cout << "Введите " << c << " элементов для " << i + 1 << " строки" << std::endl;
			for (int j = 0; j < c; ++j) { //столбцы
			std::cin >> matrix[i][j];
			}
		}
		for (int i = 0; i < r; ++i) {
			int sum = 0;
			for (int j = 0; j < c; ++j) {
			 sum += matrix[i][j];
			}
			if (f_sum) {
				maxim_sum = sum;
				row = i;
				f_sum = 0;
			}
			if (abs(sum) > abs(maxim_sum)) { 
				maxim_sum = sum;
				row = i;
			}
			for (int i = 0; i < c; ++i) {
				matrix[row][i] = 999; //замена значений
			}
			for (i = 0; i < r; ++i) {
				std::cout << std::endl;
				for (int j = 0; j < c; ++j) {

		std::cout << matrix[i][j] << " ";  
				}
			}
		}
		return 0;
	}





