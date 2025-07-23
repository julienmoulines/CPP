#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept>  // Pour std::exception
#include <cstddef>    // Pour size_t

template <typename T>
class Array{
	public: 
		Array();                                   // constructeur par défaut
		Array(unsigned int n);                     // constructeur avec taille
		Array(const Array& other);                 // constructeur de copie
		Array& operator=(const Array& other);      // opérateur d'affectation
		~Array(); 
		T& operator[](unsigned int index);         // Accès par indice | opérateur []
		const T& operator[](unsigned int index) const;
		unsigned int size() const;

	private:
		T* _array;  								// Pointeur vers le tableau dynamique
    	unsigned int _size;
};

#include "../srcs/Array.tpp"

# endif