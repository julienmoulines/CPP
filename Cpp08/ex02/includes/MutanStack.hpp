#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack> // base : std::stack

template<typename T>
class MutantStack : public std::stack<T> {
public:
    // Constructeur par défaut
    MutantStack() {}

    // Constructeur de copie
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}

    // Destructeur
    ~MutantStack() {}

    // Opérateur d'affectation
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

    // Définir un alias pour le type d'itérateur interne
    typedef typename std::stack<T>::container_type::iterator iterator;

    // Ajout des fonctions begin() et end()
    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};

#endif
