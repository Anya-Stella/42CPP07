#pragma once
#include <cstddef>

template <typename T>
void	iter(T* array, const std::size_t len, void (*func)(T &))
{
	for (std::size_t i = 0; i < len; ++i)
	{
		func(array[i]);
	}
}

template <typename T>
void	iter(const T* array, const std::size_t len, void (*func)(const T &))
{
	for (std::size_t i = 0; i < len; ++i)
	{
		func(array[i]);
	}
}
