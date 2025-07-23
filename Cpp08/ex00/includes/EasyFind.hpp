#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error

template <typename T>
typename T::iterator easyfind(T& container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) // .end et similaire au \0 en C, ne contient pas de valeur
    	throw std::runtime_error("Element not found"); //Runtime car erreur non détécté au compilateur, ici, valeur introuvable
	return it;
}

# endif