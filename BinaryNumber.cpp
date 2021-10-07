#include "BinaryNumber.h"

namespace vz_pract
{
	int BinaryNumber::idCounter = 0;

	BinaryNumber::BinaryNumber()
	{
		id = ++idCounter;
		max_binary_lenght = 10;
		binary_string = new char[max_binary_lenght + 1]{ '0','0','0', '0', '0', '0', '0', '0', '0','1' };
		binary_string[max_binary_lenght] = '\0';
		std::cout << "\nCоздана строка <" << id << "> \n";
	}

	BinaryNumber::BinaryNumber(int array_size, char* array_of_number)
	{
		id = ++idCounter;
		max_binary_lenght = array_size;
		binary_string = new char[max_binary_lenght] {0};

		for (int i = 0; i < max_binary_lenght; i++)
		{
			binary_string[i] = array_of_number[i];
		}
		binary_string[max_binary_lenght] = '\0';
		std::cout << "\nCоздана строка <" << id << "> \n";
	}

	BinaryNumber::BinaryNumber(const BinaryNumber& string_of_number)
	{
		id = ++idCounter;
		max_binary_lenght = string_of_number.max_binary_lenght;
		binary_string = new char[max_binary_lenght + 1];
		for (int i = 0; i < max_binary_lenght; i++)
		{
			binary_string[i] = string_of_number.binary_string[i];
		}
		binary_string[max_binary_lenght] = '\0';
		std::cout << "\nCоздана строка <" << id << "> \n";
	}

	BinaryNumber::~BinaryNumber()
	{
		delete[] binary_string;
		std::cout << "\nУничтожена строка <" << id << "> \n";
	}

	int BinaryNumber::get_max_binary_lenght() const
	{
		return max_binary_lenght;
	}

	char* BinaryNumber::get_binary_string() const
	{
		return binary_string;
	}

	void BinaryNumber::set_binary_string(const char* array_of_number)
	{
		max_binary_lenght = strlen(array_of_number);
		delete[] binary_string;
		binary_string = new char[max_binary_lenght + 1];
		for (int i = 0; i < max_binary_lenght; i++)
		{
			binary_string[i] = array_of_number[i];
		}
		binary_string[max_binary_lenght] = '\0';
	}

	void BinaryNumber::out_binary_string() const
	{
		for (int i = 0; i < max_binary_lenght; i++)
		{
			std::cout << binary_string[i];
		}
	}

	const BinaryNumber& BinaryNumber::operator= (const BinaryNumber& string_of_number)
	{
		if (this == &string_of_number)
			return *this;

		delete[] binary_string;
		max_binary_lenght = string_of_number.max_binary_lenght;

		if (string_of_number.binary_string)
		{
			binary_string = new char[max_binary_lenght + 1];
			for (int i = 0; i < max_binary_lenght; i++)
				binary_string[i] = string_of_number.binary_string[i];
			binary_string[max_binary_lenght] = '\0';
		}
		else
			binary_string = 0;

		return *this;
	}

	std::ostream& operator<< (std::ostream& out, const BinaryNumber& string_of_number)
	{
		for (int i = 0; i < string_of_number.max_binary_lenght; i++)
		{
			out << string_of_number.binary_string[i];
		}
		out << "\n";
		return out;
	}

	const BinaryNumber& BinaryNumber::operator >> (int bits)
	{
		int safe;
		for (int i = 0; i < bits; i++)
		{
			safe = binary_string[max_binary_lenght - 1];
			for (int j = max_binary_lenght - 1; j > 0; j--)
			{
				binary_string[j] = binary_string[j - 1];
			}
			binary_string[0] = safe;
		}
		return *this;
	}

	const BinaryNumber& BinaryNumber::operator << (int bits)
	{
		int safe;
		for (int i = 0; i < bits; i++)
		{
			safe = binary_string[0];
			for (int j = 1; j < max_binary_lenght; j++)
			{
				binary_string[j - 1] = binary_string[j];
			}
			binary_string[max_binary_lenght - 1] = safe;
		}
		return *this;
	}

	//Копия инверсии создается потому что, мне кажется, что это немного правильней
	//Посмотрим на конкретном примере:
	//Допустим я где-то в условии, буду проверять 
	// bool a(){
	// a = true
	// if(~a == false)...
	//}
	// при этом само "а" изменится, и всё пойдет на перекосяк
	//или же
	//например ~S1 || S1 сделать
	//А вот и не получится, если нового объекта не создавать

	BinaryNumber BinaryNumber::operator~()
	{
		BinaryNumber res(*this);
		for (int i = 0; i < max_binary_lenght; i++)
		{
			if (binary_string[i] == '0') res.binary_string[i] = '1';
			else
				if (binary_string[i] == '1') res.binary_string[i] = '0';
		}
		return res;
	}
}
