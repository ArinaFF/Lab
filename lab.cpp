#include <iostream>
#include <cmath> // подключаем для того чтобы взять под корень
int main()
{
	
	int x,y,z; //стороны треугольника. тип данных - целочисленный, тк считать будет легче
	std::cout << " Enter x: ";  //просим пользователя ввести числа
	std::cin >> x;
	std::cout << " Enter y: ";
	std::cin >> y;
	std::cout << " Enter z: ";
	std::cin >> z;
	

	float p = (x + y + z) / 2.0f; // находим полупериметр, который мы подставим в формулу
	float s = sqrt(p * (p - x) * (p - y) * (p - z)); // площадь Герона   

	std::cout << "x = "<< x << ", size = " << sizeof(x) * 8  << std::endl;          // название переменной, ее значение и размер  
	std::cout << "y = " << y << ", size = " << sizeof(y) * 8  << std::endl;
	std::cout << "z = " << z << ", size = "<< sizeof(z) * 8  << std::endl;
	std::cout << "s = " << s << ", size = " << sizeof(s) * 8  << std::endl;
	std::cout << "Max float value: " << std::numeric_limits<float>::max() << std::endl; // макс значение 
	std::cout << "Min float value: " << std::numeric_limits<float>::min() << std::endl;// мин значение
		

}          
