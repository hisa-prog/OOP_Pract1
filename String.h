#pragma once
#include <iostream>
#include <fstream>

namespace vz_pract 
{
	class String { //������������� binnary_number
	private:
		int N; //max_binnary_lenght
		char* S; //binnary_string

		int id;
		static int idCounter;

	public:
		String();
		String(int array_size, char* array_of_number);
		String(const String& string_of_number);
		~String();

		int get_string_size() const; //��������� ������� ������ //get_N
		char* get_string() const;//��������� ������//get_S
		void set_string(char* array_of_number); 
		void out_string() const; //����� ������

		const String& operator= (const String& string_of_number);
		friend std::ostream& operator<< (std::ostream& out, const String& string_of_number);
		const void operator >> (int bits); //����������� ����� ������
		const void operator << (int bits); //����������� ����� �����
		const void operator ~ (); // ��������
	};

}
