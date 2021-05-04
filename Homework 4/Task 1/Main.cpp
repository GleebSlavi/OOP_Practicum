#include <iostream>
#include "Vector.h"

template <class T>
using map = void (*)(T&);

template <class T>
using filter = bool (*)(T);

template <class T>
using reduce = T (*)(T, T);

template <class T>
struct SmartFunc
{
	map<T> mapPtr;
	filter<T> filterPtr;
	reduce<T> reducePtr;

	SmartFunc()
	{
		mapPtr = nullptr;
		filterPtr = nullptr;
		reducePtr = nullptr;
	}

	void setMap(map<T> mapPtr)
	{
		this->mapPtr = mapPtr;
	}

	void setFilter(filter<T> filterPtr)
	{
		this->filterPtr = filterPtr;
	}

	void setReduce(reduce<T> reducePtr)
	{
		this->reducePtr = reducePtr;
	}

	void useMap(Vector<T>& vec)
	{
		if (mapPtr == nullptr)
		{
			std::cout << "Pointer doesnt point to function!" << std::endl;
			return;
		}

		for (size_t i = 0; i < vec.getVectorSize(); ++i)
		{
			mapPtr(vec[i]);
		}
	}

	void useFilter(Vector<T>& vec)
	{
		if (filterPtr == nullptr)
		{
			std::cout << "Pointer doesnt point to function!" << std::endl;
			return;
		}

		Vector<T> newVector;
		for (size_t i = 0; i < vec.getVectorSize(); ++i)
		{
			if (filterPtr(vec[i]))
			{
				newVector.addAtEnd(vec[i]);
			}
		}
		vec = newVector;
	}

	T useReduce(Vector<T>& vec)
	{
		if (reducePtr == nullptr)
		{
			std::cout << "Pointer doesnt point to function!" << std::endl;
			return 0;
		}

		T reduceVariable = vec[0];
		for (size_t i = 1; i < vec.getVectorSize(); ++i)
		{
			reduceVariable = reducePtr(reduceVariable,vec[i]);
		}
		return reduceVariable;
	}

	void useFilterWithMap(Vector<T>& vec)
	{
		useFilter(vec);
		useMap(vec);
	}

	T useFilterWithReduce(Vector<T>& vec)
	{
		useFilter(vec);
		return useReduce(vec);
	}

	T useMapWithReduce(Vector<T>& vec)
	{
		useMap(vec);
		return useReduce(vec);
	}
};


void addTwo(int& element)
{
	element += 2;
}

bool isEven(int element)
{
	return element % 2 == 0;
}

int sumTwoElements(int firstElement, int secondElement)
{
	return firstElement + secondElement;
}


int main()
{
	Vector<int> vec;
	vec.addAtEnd(1);
	vec.addAtEnd(2);
	vec.addAtEnd(3);
	vec.addAtEnd(4);
	vec.addAtEnd(5);

	SmartFunc<int> smartFunc;
	smartFunc.setReduce(sumTwoElements);
	smartFunc.setFilter(isEven);
	smartFunc.setMap(addTwo);
	std::cout << smartFunc.useReduce(vec);

	return 0;
}