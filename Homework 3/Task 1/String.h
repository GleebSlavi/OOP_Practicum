#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
	char* string;
	size_t stringSize;
	size_t stringCapacity;

	void copy(const String&);
	void erase();
public:
	String();
	String(const String&);
	String& operator=(const String&);
	~String();

	void setString(const char*, size_t, size_t);

	const char* getString() const;
	size_t getStringSize() const;
	size_t getStringCapacity() const;

	bool operator==(const String& other);
	char operator[](size_t index);
};

