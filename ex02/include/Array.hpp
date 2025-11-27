#pragma once
#include <stdexcept>

template <typename T>
class Array
{
private:
	T				*_data;
	unsigned int	_len;

public:
	Array();
	Array(unsigned int len);
	Array(const Array &other);
	Array	&operator=(const Array &rhs);
	~Array();

	// access[]
	// ⚪︎arr[3]=2;
	T	&operator[](unsigned int index);

	// ×arr[3]=2;
	const T&operator[](unsigned int index) const;
	
	// size
	unsigned int	size() const;
};

// implement

template <typename T>
Array<T>::Array() : _data(NULL), _len(0){}

template <typename T>
Array<T>::Array(unsigned int len) : _data(new T[len]), _len(len) {}

template <typename T>
Array<T>::Array(const Array<T> &other) : _data(NULL), _len(0)
{
	*this = other;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] _data;
		_len = rhs._len;

		if (_len > 0)
		{
			_data = new T[_len];
			for (unsigned int i = 0; i < rhs._len; ++i)
			{
				_data[i] = rhs._data[i];
			}
		}
		else
		{
			_data = NULL;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

// access[]
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _len)
		throw std::out_of_range("Array: index out of range");
	return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _len)
        throw std::out_of_range("Array: index out of range");
    return _data[index];
}

// size
template <typename T>
unsigned int Array<T>::size() const
{
	return _len;
}
