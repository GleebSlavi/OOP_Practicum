#include "String.h"

void String::copy(const String& other)
{
	stringSize = other.stringSize;
	stringCapacity = other.stringCapacity;
	string = new char[stringCapacity];
	strcpy_s(string, stringSize, other.string);
}

void String::erase()
{
	delete[] string;
}

String::String()
{
	stringCapacity = 3;
	stringSize = 1;
	string = new char[stringCapacity];
	string[0] = '\0';
}

String::String(const String& other)
{
	this->copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

String::~String()
{
	delete[] string;
}

void String::setString(const char* string, size_t stringSize, size_t stringCapacity)
{
	delete[] this->string;
	this->stringSize = stringSize;
	this->stringCapacity = stringCapacity;
	this->string = new char[this->stringCapacity];
	strcpy_s(this->string, this->stringSize, string);
}

const char* String::getString() const
{
	return string;
}

size_t String::getStringSize() const
{
	return stringSize;
}

size_t String::getStringCapacity() const
{
	return stringCapacity;
}

bool String::operator==(const String& other)
{
	if (stringSize != other.stringSize)
	{
		return false;
	}

	for (size_t i = 0; i < stringSize; ++i)
	{
		if (string[i] != other.string[i])
		{
			return false;
		}
	}
	return true;
}

char String::operator[](size_t index)
{
	if (index < stringSize - 1)
	{
		return string[index];
	}
}
