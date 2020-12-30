#pragma once

#ifndef _ARRAY_
#define _ARRAY_
#include <iostream>
using namespace std;


template <class T>
class Array
{
	int logSize, phySize;
	T* arr;

public:
	Array() = default;
	Array(const T& T);
	Array(int size);
	~Array();

	const Array& operator+=(const T& newVal);
	const Array& operator=(const Array& other);

	T* getArr() const { return arr; }
	friend ostream& operator<<(ostream &os, const Array& arr)
	{
		for (int i = 0; i < logSize; i++)
			os << arr[i] << ' \n';
		return os;
	}

};
//Class Array
template <class T>
Array<T>::Array(int size)
{
	phySize = size;
	logSize = 0;
	arr = new T[phySize];
}

template <class T>
Array<T>::Array(const T& T) : arr(NULL)
{
	*this = T;
}

template <class T>
Array<T>::~Array()
{
	delete[]arr;
}


template <class T>
const Array<T>& Array<T> :: operator=(const Array<T> &other)
{
	if (this->getArr() != other.getArr())
	{
		phySize = other.phySize;
		logSize = other.logSize;
		arr = new T[phySize];
		for (int i = 0; i < logSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;

}

template <class T>
const Array<T>& Array<T> :: operator+=(const T &newval)
{
	if (logSize == phySize)
	{
		phySize *= 2;
		T* NewArr = new T[phySize];
		memcpy(NewArr, arr, (logSize * sizeof(T)));
		delete[]arr;
		arr = NewArr;
	}

	arr[logSize++] = newval;

	return *this;
}



#endif