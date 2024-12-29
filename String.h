#pragma once
#include <iostream>

using namespace std;

class String {
private:
	char* string;
	int size;
	static int count;
public:
	String() : String(nullptr, 80) {};
	explicit String(int size) : String(nullptr, size) {};
	explicit String(char* string) : String(string, strlen(string) + 1) {};
	String(char* string_S, int size_S);
	String(String&& string_S);
	String(const String& string_S) : string{ string_S.string }, size{ string_S.size } { count++; }

	const char* get_string() { return string; }
	const int get_size() { return size; }
	void set_string(const char* string_S);

	void print() { printf("%s\n", string); }
	static int get_count() { return count; }

	char& operator[](int index) { return string[index]; }

	char& operator[](int index) const { return string[index]; }

	int operator()(char symbol);

	explicit operator int() const { return strlen(string); }

	friend istream& operator>> (istream& my_cin, String& str);

	~String();
};
