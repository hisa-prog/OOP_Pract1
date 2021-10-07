#pragma once
#include <iostream>
#include <fstream>

namespace vz_pract 
{
	class BinaryNumber { 
	private:
		int max_binary_lenght; 
		char* binary_string; 

		int id;
		static int idCounter;

	public:
		BinaryNumber();
		BinaryNumber(int array_size, char* array_of_number);
		BinaryNumber(const BinaryNumber& string_of_number);
		~BinaryNumber();

		int get_max_binary_lenght() const; //получение размера строки 
		char* get_binary_string() const;//получение строки
		void set_binary_string(const char* array_of_number);
		void out_binary_string() const; //вывод строки

		const BinaryNumber& operator= (const BinaryNumber& string_of_number);
		friend std::ostream& operator<< (std::ostream& out, const BinaryNumber& string_of_number);
		const BinaryNumber& operator >> (int bits); //циклический сдвиг вправо
		const BinaryNumber& operator << (int bits); //циклический сдвиг влево
		BinaryNumber operator ~ (); // инверсия 
	};

}
