#ifndef FONCTIONS_HPP
#define FONCTIONS_HPP

#include <string>
#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
	T swa = a;

	a = b;
	b = swa;
}

template <typename T>
T	min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T	max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif