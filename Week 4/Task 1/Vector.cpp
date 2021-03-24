#include "Vector.h"

void Vector::copy(const Vector& other)
{
	vector = new int[other.vectorCapacity];
	for (size_t i = 0; i < other.vectorSize; ++i)
	{
		vector[i] = other.vector[i];
	}
	vectorSize = other.vectorSize;
	vectorCapacity = other.vectorCapacity;
}

void Vector::erase()
{
	delete[] vector;
}

void Vector::resize()
{
	vectorCapacity *= 2;
	int *biggerVector = new int[vectorCapacity];

	for (size_t i = 0; i < vectorSize; ++i)
	{
		biggerVector[i] = vector[i];
	}

	delete[] vector;
	vector = biggerVector;
}

void Vector::swap(int& firstElement, int& secondElement)
{
	int swapTemp = firstElement;
	firstElement = secondElement;
	secondElement = swapTemp;
}

Vector::Vector()
{
	vectorSize = 0;
	vectorCapacity = 3;
	vector = new int[vectorCapacity];
}

Vector::Vector(const Vector& other)
{
	this->copy(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Vector::~Vector()
{
	delete[] vector;
}

void Vector::setVector(int vector[], size_t vectorSize, size_t VectorCapacity)
{
	delete[] this->vector;
	this->vector = new int[vectorCapacity];
	for (size_t i = 0; i < vectorSize; ++i)
	{
		this->vector[i] = vector[i];
	}
	this->vectorSize = vectorSize;
	this->vectorCapacity = VectorCapacity;
}

int* Vector::getVector() const
{
	return vector;
}

size_t Vector::getVectorSize() const
{
	return vectorSize;
}

size_t Vector::getVectorCapacity() const
{
	return vectorCapacity;
}

void Vector::addAtEnd(int element)
{
	if (vectorSize >= vectorCapacity)
	{
		this->resize();
	}

	vector[vectorSize] = element;
	++vectorSize;
}

void Vector::removeAtEnd()
{
	if (vectorSize > 0)
	{
		--vectorSize;
	}
}

void Vector::addAtStart(int element)
{
	if (vectorSize >= vectorCapacity)
	{
		this->resize();
	}

	for (size_t i = 0; i < vectorSize; ++i)
	{
		swap(vector[i], vector[vectorSize]);
	}
	vector[0] = element;
	++vectorSize;
}

void Vector::removeAtStart()
{
	for (size_t i = 0; i < vectorSize - 1; ++i)
	{
		swap(vector[i], vector[i + 1]);
	}
	--vectorSize;
}

void Vector::removeAt(int index)
{
	if (index >= vectorSize)
	{
		std::cout << "Index too big!" << std::endl;
		return;
	}

	for (size_t i = index; i < vectorSize - 1; ++i)
	{
		swap(vector[i], vector[i + 1]);
	}
	--vectorSize;
}

int Vector::operator[](size_t index) const
{
	if (index >= vectorSize)
	{
		std::cout << "Index too big!" << std::endl;
		return 0;
	}
	return vector[index];
}

Vector& Vector::operator+(const Vector& other)
{
	vectorCapacity += other.vectorCapacity;
	int* newVector = new int[vectorCapacity];
	for (int i = 0; i < vectorSize; ++i)
	{
		newVector[i] = vector[i];
	}

	int index = 0;
	for (size_t i = vectorSize; i < vectorSize + other.vectorSize; ++i)
	{
		newVector[i] = other.vector[index];
		++index;
	}
	vectorSize += other.vectorSize;

	delete[] vector;
	vector = newVector;
	return *this;
}

void Vector::printVector() const
{
	for (size_t i = 0; i < vectorSize; ++i)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

