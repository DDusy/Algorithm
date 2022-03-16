#pragma once
#include <iostream>

template<typename T>
class MyVector
{
public:
	MyVector() {}
	
	~MyVector()
	{
		if (_Data)
			delete[] _Data;
	}

	void push_back(const T& _data);
	void Pop_back();
	void reserve(int _capacity);

	T& operator[](const int _pos) { return _Data[_pos]; }


	int size() { return Size; }
	int capacity() { return Capacity; }
	int back() { return _Data[Size - 1]; }
	int front() { return _Data[0]; }

	void clear();

private:
	T* _Data = nullptr;
	int Size = 0;
	int Capacity = 0;
};

template<typename T>
inline void MyVector<T>::push_back(const T& _value)
{
	if (Size == Capacity)
	{
		int newCapacirty = static_cast<int>(Capacity * 1.5);

		if (newCapacirty == Capacity)
			++newCapacirty;

		reserve(newCapacirty);
	}
	
	_Data[Size] = _value;
	++Size;
}

template<typename T>
inline void MyVector<T>::Pop_back()
{

	if (Size <= 0)
		return;

	--Size;

	T* newData = new T[Capacity];

	memcpy_s(newData, sizeof(_Data) * Size, _Data, sizeof(_Data) * Size);

	if (_Data)
		delete[] _Data;

	_Data = newData;
}

template<typename T>
inline void MyVector<T>::reserve(int _capacity)
{
	if (Capacity>= _capacity)
		return;

	T* newData = new T[_capacity];

	if (_Data)
	{
		memcpy_s(newData, sizeof(_Data)*Size,_Data, sizeof(_Data) * Size);


		if (_Data)
			delete[] _Data;
	}

	_Data = newData;

	Capacity = _capacity;
}

template<typename T>
inline void MyVector<T>::clear()
{
	if (_Data)
	{
		delete[] _Data;
		_Data = new T[Capacity];
	}

	Size = 0;
}
