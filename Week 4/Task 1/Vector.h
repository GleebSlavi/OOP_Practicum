#pragma once
#include <iostream>
#include <cstring>

class Vector
{
private:
	int* vector;
	size_t vectorSize;
	size_t vectorCapacity;

	void copy(const Vector& other);
	void erase();
	void resize();
	void swap(int& firstElement, int& secondELement);
public:
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void setVector(int vector[], size_t vectorSize, size_t VectorCapacity);

	int* getVector() const;
	size_t getVectorSize() const;
	size_t getVectorCapacity() const;

	void addAtEnd(int element);
	void removeAtEnd();
	void addAtStart(int element);
	void removeAtStart();
	void removeAt(int index);

	int operator[](size_t index) const;
	Vector& operator+(const Vector& other);

	void printVector() const;
};

