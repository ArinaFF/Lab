#include <iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
	int A, sum, m_num, num_i, i;

	sum = 0;
	// пункт 1

	std::cout << "Введите количество чисел последовательности " << std::endl;
	std::cin >> A;
	std::cout << "Введите числo" << std::endl;
	i = 0;
	for (int i = 1; i <= A; ++i) {
		int N;

		std::cin >> N;

		bool mn = false; // изначально нет макс числа

		if ((N % 3 != 0) && (N % 5 != 0) && (N % 7 != 0)) { //условие

			sum += N; // сумма чисел

			if (!mn) {
				m_num = N;
				num_i = i;
				mn = true;

				if (N > m_num) { // если есть число больше, то берем его
					m_num = N;
					num_i = i;

				}

			}
		}
		if (!mn) {
			std::cout << " нет таких чисел"<< std::endl;
		}
		else {
			std::cout << "Сумма чисел: " << sum << std::endl;
			std::cout << "Номер: " << num_i << std::endl;
			std::cout << "Макс число:" << m_num << std::endl;
		}
	}

	// пункт 2


	int x;
	std::cout << " Введите число не больше 1000 по модулю" << std::endl;
	std::cin >> x;
	int n = 0;
	int a = 0; //для подсчета разрядов 
	x = abs(x);
	while (x != 0) {
		n = x % 10; 
		
	x /= 10; //счет разрядов
	++a;
	}

	std::cout << "первая цифра числа: " << n << std::endl;
	std::cout << "количество разрядов числа: " << a << std::endl;


	}


