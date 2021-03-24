#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
	char* string;
	size_t stringSize;
	size_t stringCapacity;

	void copy(const String& other);
	void erase();
	void resize();
	void swap(char& firstSymbol, char& secondSymbol);
public:
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void setString(const char string[], size_t stringSize, size_t stringCapacity);

	const char* getString() const;
	size_t getStringSize() const;
	size_t getStringCapacity() const;

	void add(char symbol);

	void insertAt(size_t index);
	void removeAt(size_t index);
	void trimStart();
	void trimEnd();
	void trimStart(size_t number);
	void trimEnd(size_t number);

	String& operator+(const String& other);
	String& operator+=(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	char operator[](size_t index);
};

