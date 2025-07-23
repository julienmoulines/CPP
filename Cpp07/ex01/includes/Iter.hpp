#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename F>
void Iter(T* array, size_t length, const F& fonction)
{
	for (size_t i = 0; i < length; ++i)
    	fonction(array[i]);
}

# endif 