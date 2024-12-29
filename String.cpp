#include "String.h"

String::String(char* string_S, int size_S) : string{ new char[size_S] }, size{ size_S }
{
	count++;
	if (string_S)
	{
		strcpy_s(string, size_S, string_S);
	}
}
String::String(String&& string_S) : string{ string_S.string }, size{ string_S.size }
{
	string_S.string = nullptr;
	string_S.size = 0;
	count++;
}

void String::set_string(const char* string_S)
{
	size = strlen(string) + 1;

	if (string)
	{
		delete[] string;
	}
	string = new char[size];
	strcpy_s(string, size, string_S);
}

int String::operator()(char symbol)
{
	for (int i{ 0 }; i < strlen(string); i++)
	{
		if (string[i] == symbol)
		{
			return i;
		}
	}

	return -1;
}

int String::count{ 0 };

String::~String()
{
	count--;
	delete[] string;
}

istream& operator>> (istream& my_cin, String& str)
{
	char buffer[100]{};

	gets_s(buffer);
	strcpy_s(str.string, strlen(buffer) + 1, buffer);

	return my_cin;
}