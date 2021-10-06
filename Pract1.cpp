#include <iostream>
#include "BinaryNumber.h"

/*
7)Класс инкапсулирует двоичное число, хранимое в виде строки S максимальной длины N. 
Определить операции циклического сдвига двоичного числа вправо или влево, 
а также инверсии этого числа (<<, >>, ~).
*/

using namespace vz_pract;

bool check_number(char* num, int size_of_number)//Проверка введенной строки на ограничения
{
	for (int i = 0; i < size_of_number; i++)
	{
		if ((num[i] != '0') && (num[i] != '1'))
		{
			return true;
		}
	}
	return false;
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int size_of_number;
	std::cout << "Введите длину строки: \n";
	std::cin >> size_of_number;

	
	char* number = new char[size_of_number]; //массив символов, который будет внесен в строку.
	do
	{
		std::cout << "Введите двоичное число: \n";
		for (int i = 0; i < size_of_number; i++)
		{
			std::cin >> number[i];
		}
		number[size_of_number] = '\0';
	} while (check_number(number, size_of_number));

	std::cout << "Введенное число: \n";

	for (int i = 0; i < size_of_number; i++) {
		std::cout << number[i];
	}

	{
		BinaryNumber S_1 = BinaryNumber(); //создаем строку по умолчанию
		S_1.set_binary_string(number); //вносим туда значения вышевведенной строки
		std::cout << "\nВведенная строка:\n";
		S_1.out_binary_string();

		int number_cycle_right;
		std::cout << "\nВведите кол-во циклического сдвига вправо:\n";
		std::cin >> number_cycle_right;

		std::cout << "\nПобитовый сдвиг числа вправо:";
		S_1 >> number_cycle_right;
		std::cout << "= ";
		S_1.out_binary_string();

		int number_cycle_left;
		std::cout << "\nВведите кол-во циклического сдвига влево:\n";
		std::cin >> number_cycle_left;

		std::cout << "\nПобитовый сдвиг числа влево:";
		S_1 << number_cycle_left;
		std::cout << "= ";
		S_1.out_binary_string();

		std::cout << "\nИнверсия числа " << S_1; //беда, не робит! Не получилось переделать
		BinaryNumber S_2 = BinaryNumber();
		S_2 = ~S_1;
		std::cout << "= ";
		S_2.out_binary_string();
	}
	std::cout << "Конец программы!" << std::endl;
}