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
	Vector& operator=(const Vector<T>&);
	~Vector();

	void setVector(T*, size_t, size_t);

	T* getVector() const;
	size_t getVectorSize() const;
	size_t getVectorCapacity() const;

	void addAtEnd(T);
	void removeAtEnd();
	void addAtStart(T);
	void removeAtStart();
	void removeAt(size_t);
	T& operator[](size_t) const;

	void printVector() const;
};

template<class T>
void Vector<T>::copy(const Vector<T>& other)
{
	vectorSize = other.vectorSize;
	vectorCapacity = other.vectorCapacity;

	vector = new T[vectorCapacity];
	for(size_t i=0;i<vectorSize;++i)
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
void Vector<T>::setVector(T* vector, size_t vectorSize, size_t vectorCapacity)
{
	this->vectorSize = vectorSize;
	this->vectorCapacity = vectorCapacity;

	delete[] this->vector;
	this->vector = new T[vectorCapacity];
	for (size_t i = 0; i < vectorSize; ++i)
	{
		this->vector[i] = vector[i];
	}
}

template <class T>
T* Vector<T>::getVector() const
{
	return vector;
}

template<class T>
size_t Vector<T>::getVectorSize() const
{
	return vectorSize;
}

template<class T>
size_t Vector<T>::getVectorCapacity() const
{
	return vectorCapacity;
}

template<class T>
void Vector<T>::addAtEnd(T element)
{
	if (vectorSize >= vectorCapacity)
	{
		this->resize();
	}
	vector[vectorSize] = element;
	++vectorSize;
}

template<class T>
void Vector<T>::removeAtEnd()
{
	--vectorSize;
}

template<class T>
void Vector<T>::addAtStart(T element)
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

template<class T>
void Vector<T>::removeAtStart()
{
	for (size_t i = 0; i < vectorSize - 1; ++i)
	{
		swap(vector[i], vector[i + 1]);
	}
	--vectorSize;
}

template<class T>
void Vector<T>::removeAt(size_t index)
{
	if (index > vectorSize - 1)
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

template<class T>
T& Vector<T>::operator[](size_t index) const
{
	if (index <= vectorSize - 1)
	{
		return vector[index];
	}
	else
	{
		std::cout << "Invalid index!" << std::endl;
	}
}

template<class T>
void Vector<T>::printVector() const
{
	for (size_t i = 0; i < vectorSize; ++i)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}
