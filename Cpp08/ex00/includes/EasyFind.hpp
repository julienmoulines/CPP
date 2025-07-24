#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error

//iterator est un objet qui peut itérer sur un containner

template <typename T>
typename T::iterator easyfind(T& container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
    	throw std::runtime_error("Element not found"); //Runtime car erreur non détécté au compilateur, ici, valeur introuvable
	return it;
}

# endif