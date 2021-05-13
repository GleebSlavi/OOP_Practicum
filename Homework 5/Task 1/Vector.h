#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T* vector;
	size_t vectorSize;
	size_t vectorCapacity;

	void copy(const Vector<T>&);
	void erase();
	void resize();
	void swap(T&, T&);

public:
	Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

	size_t getSize() const;

	void moveToTheBack();
	void addCoin(Coin*);
	void add(const T&);
	void removeFromIndex(size_t);
	T& operator[](size_t) const;

	void printData() const;
};

template<class T>
void Vector<T>::copy(const Vector<T>& other)
{
	vectorSize = other.vectorSize;
	vectorCapacity = other.vectorCapacity;

	vector = new T[vectorCapacity];
	for (size_t i = 0; i < vectorSize; ++i)
	{
		vector[i] = other.vector[i];
	}
}

template<class T>
void Vector<T>::erase()
{
	delete[] vector;
}

template<class T>
void Vector<T>::resize()
{
	vectorCapacity *= 2;

	T* biggerVector = new T[vectorCapacity];
	for (size_t i = 0; i < vectorSize; ++i)
	{
		biggerVector[i] = vector[i];
	}

	delete[] vector;
	vector = biggerVector;
}

template<class T>
void Vector<T>::swap(T& firstElement, T& secondElement)
{
	T swapTemp = firstElement;
	firstElement = secondElement;
	secondElement = swapTemp;
}

template<class T>
Vector<T>::Vector()
{
	vectorCapacity = 3;
	vectorSize = 0;

	vector = new T[vectorCapacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

template<class T>
Vector<T>::~Vector()
{
	this->erase();
}

template<class T>
size_t Vector<T>::getSize() const
{
	return vectorSize;
}

template<class T>
void Vector<T>::moveToTheBack()
{
	for (size_t i = 0; i < vectorSize - 1; ++i)
	{
		swap(vector[i], vector[i + 1]);
	}
}

template<class T>
void Vector<T>::addCoin(Coin* element)
{
	if (vectorSize >= vectorCapacity)
	{
		this->resize();
	}
	vector[vectorSize] = element;
	++vectorSize;
}

template<class T>
void Vector<T>::add(const T& element)
{
	if (vectorSize >= vectorCapacity)
	{
		this->resize();
	}
	vector[vectorSize] = element;
	++vectorSize;
}

template<class T>
void Vector<T>::removeFromIndex(size_t index)
{
	if (index >= vectorSize)
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	for (size_t i = index; i < vectorSize - 1; ++i)
	{
		swap(vector[i], vector[i + 1]);
	}
	--vectorSize;
}

template<class T>
T& Vector<T>::operator[](size_t index) const
{
	return vector[index];
}

template<class T>
void Vector<T>::printData() const
{
	for (size_t i = 0; i < vectorSize; ++i)
	{	
		std::cout<<"Product "<<i+1<<": "<<std::endl;
		std::cout << vector[i] << std::endl;
	}
}
