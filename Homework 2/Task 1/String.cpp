#include "String.h"

void String::copy(const String& other)
{
	string = new char[other.stringCapacity];
	strcpy_s(string, other.stringSize, other.string);
	stringSize = other.stringSize;
	stringCapacity = other.stringCapacity;
}

void String::erase()
{
	delete[] string;
}

void String::resize()
{
	stringCapacity *= 2;
	char *biggerString = new char[stringCapacity];
	strcpy_s(biggerString, stringSize, string);

	delete[] string;
	string = biggerString;
}

void String::swap(char& firstSymbol, char& secondSymbol)
{
	char swapTemp = firstSymbol;
	firstSymbol = secondSymbol;
	secondSymbol = swapTemp;
}

String::String()
{
	stringSize = 1;
	stringCapacity = 5;
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
	this->erase();
}

void String::setString(const char string[], size_t stringSize, size_t stringCapacity)
{
	delete[] this->string;
	this->string = new char[stringCapacity];
	strcpy_s(this->string, stringSize, string);
	this->stringSize = stringSize;
	this->stringCapacity = stringCapacity;
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

void String::add(char symbol)
{
	if (stringSize >= stringCapacity)
	{
		this->resize();
	}

	string[stringSize] = symbol;
	++stringSize;
}

void String::insertAt(size_t index)
{
	if (index >= stringSize - 1)
	{
		std::cout << "Index too big!" << std::endl;
		return;
	}

	if (stringSize >= stringCapacity)
	{
		this->resize();
	}

	char symbol;
	std::cout << "Enter symbol: ";
	std::cin >> symbol;

	for (size_t i = 0; i < stringSize - index; ++i)
	{
		swap(string[stringSize - 1 - i], string[stringSize - i]);
	}
	string[index] = symbol;
	++stringSize;
}

void String::removeAt(size_t index)
{
	if (index >= stringSize - 1)
	{
		std::cout << "Index too big!" << std::endl;
		return;
	}

	for (size_t i = index; i < stringSize; ++i)
	{
		swap(string[i], string[i + 1]);
	}
	--stringSize;
}

void String::trimStart()
{
	for (size_t i = 0; i < stringSize; ++i)
	{
		swap(string[i], string[i + 1]);
	}
	--stringSize;
}

void String::trimEnd()
{
	swap(string[stringSize - 2], string[stringSize - 1]);
	--stringSize;
}

void String::trimStart(size_t number)
{
	for (size_t i = 0; i < number; ++i)
	{
		for (size_t j = 0; j < stringSize; ++j)
		{
			swap(string[j], string[j + 1]);
		}
		--stringSize;
	}
}

void String::trimEnd(size_t number)
{
	for (size_t i = 0; i < number; ++i)
	{
		swap(string[stringSize - 2], string[stringSize - 1]);
		--stringSize;
	}
}

String& String::operator+(const String& other)
{
	stringCapacity += other.stringCapacity;
	char* tempString = new char[stringCapacity];
	strcpy_s(tempString, stringSize, string);

	int index = 0;
	for (int i = stringSize - 1; other.string[index] != '\0'; ++i)
	{
		tempString[i] = other.string[index];
		++index;
	}
	stringSize += (other.stringSize - 1);
	tempString[stringSize - 1] = '\0';

	delete[] string;
	string = tempString;
	return *this;
}

String& String::operator+=(const String& other)
{
	this->operator+(other);
	return *this;
}

bool String::operator==(const String& other)
{
	for (size_t i = 0; i < stringSize; ++i)
	{
		if (string[i] != other.string[i])
		{
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& other)
{
	if (this->operator==(other))
	{
		return false;
	}
	return true;
}

char String::operator[](size_t index)
{
	if (index >= stringSize - 1)
	{
		std::cout << "Index too big!" << std::endl;
		return 0;
	}
	return string[index];
}