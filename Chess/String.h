#pragma once
#include <cstring>
#include <iostream>
class String
{
private:
	void Resize();
	int count;
	int capacity;
	char* string;
	void copyFunc(const String& string);
public:
	String();
	String(char* string);
	~String();
	String(const String& string);
	String& operator=(const String& string);
	bool operator==(const char* string);
	const char* GetString() const;
	int Length();
	void Append(const char* string);
	void Append(const char c);
	void Append(const String& string);
	void Insert(const int index, const char c);
	void Insert(const int index, const char* string);
	void Insert(const int index, const String& string);
	void Remove(const int index);
	void Remove(const int fromIndex, const int toIndex);
	void Replace(const char replaceME, const char pasteME);
	void Replace(const char replaceMe, const char pasteMe, const int fromIndex, const int toIndex);
	void Clear();

	String operator+(const String& string);
	void Print();
	char operator[](const int index);
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	friend std::istream& operator >> (std::istream& stream, String& string);
};