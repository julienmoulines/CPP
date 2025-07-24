#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

/*Le conteneur std::stack n'est pas itérable, 
//donc on crée une classe MutantStack qui hérite de std::stack 
et expose des itérateurs vers son conteneur interne. */


template <typename T>
class MutantStack : public std::stack<T> //derive de stack pour les methodes push, top ect...
{
public:
	MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack();

	// std::stack encapsule un container sous-jacent (c, généralement un std::deque<T>). On accède à ses itérateurs avec container_type.
	// pour parcourir la stack
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

# include "../srcs/MutantStack.tpp"

#endif