#include "String.h"

namespace vz_pract 
{
	int String::idCounter = 0;

	String::String() 
	{
		id = ++idCounter;
		N = 10;
		S = new char[N] {'0','0','0', '0', '0', '0', '0', '0', '0','1'};
		std::cout << "\nCоздана строка <" << id << "> \n";
	}

	String::String(int array_size, char* array_of_number)
	{
		id = ++idCounter;
		N = array_size;
		S = new char[N] {0};

		for (int i = 0; i < N; i++)
		{
			S[i] = array_of_number[i];
		}
		S[N] = '\0';
		std::cout << "\nCоздана строка <" << id << "> \n";
	}

	String::String(const String& string_of_number)
	{
		id = ++idCounter;
		N = string_of_number.N;
		S = new char[N] {0};
		for (int i = 0; i < N; i++)
		{
			S[i] = string_of_number.S[i];
		}
		S[N] = '\0';
		std::cout << "\nCоздана строка <" << id << "> \n";
	}

	String::~String()
	{
		delete[] S;
		std::cout << "\n”ничтожена строка <" << id << "> \n";
	}

	int String::get_string_size() const
	{
		return N;
	}

	char* String::get_string() const 
	{
		return S;
	}

	void String::set_string(char* array_of_number) 
	{
		N = strlen(array_of_number);
		S = new char[N] {0};
		for (int i = 0; i < N; i++) 
		{
			S[i] = array_of_number[i];
		}
		S[N] = '\0';
	}

	void String::out_string() const
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << S[i];
		}
	}

	const String& String::operator= (const String& string_of_number) 
	{
		N = string_of_number.N;
		S = new char[N] {0};
		for (int i = 0; i < N; i++)
		{
			S[i] = string_of_number.S[i];
		}
		S[N] = '\0';
		return *this;
	}

	std::ostream& operator<< (std::ostream& out, const String& string_of_number)
	{
		for (int i = 0; i < string_of_number.N; i++)
		{
			out << string_of_number.S[i];
			}
			out << "\n";
		return out;
	}

	const void String::operator >> (int bits)
	{
		int safe;
		for (int i = 0; i < bits; i++)
		{
			safe = S[N - 1];
			for (int j = N-1; j > 0; j--)
			{
				S[j] = S[j-1];
			}
			S[0] = safe;
		}
		//return *this;
	}

	const void String::operator << (int bits)
	{
		int safe;
		for (int i = 0; i < bits; i++)
		{
			safe = S[0];
			for (int j = 1; j < N; j++)
			{
				S[j-1] = S[j];
			}
			S[N-1] = safe;
		}
	//	return *this;
	}

	const void String::operator ~ ()
	{
		for (int i = 0; i < N; i++)
		{
			if (S[i] == '0') S[i] = '1';
			else
				if (S[i] == '1') S[i] = '0';
		}
		//return *this;
	}
}
