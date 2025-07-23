#include "../includes/Array.hpp"

// Constructeur par défaut : crée un tableau vide
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
    // On initialise le pointeur à NULL et la taille à 0
}

// Constructeur avec taille : crée un tableau avec n éléments par défaut
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    // On alloue dynamiquement un tableau de taille n
    // Chaque élément est initialisé avec le constructeur par défaut de T
}

// Constructeur par copie : copie les valeurs d’un autre tableau
template <typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL), _size(0) {
    // Initialisation vide
    *this = other; // Appelle l’opérateur d’affectation pour faire la copie
}

// Destructeur : libère la mémoire allouée dynamiquement
template <typename T>
Array<T>::~Array() {
    delete[] _array; // Utilisation de delete[] pour libérer un tableau
}

// Opérateur d’affectation : copie chaque élément d’un tableau à un autre
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) { // Vérifie l'auto-affectation
        delete[] _array; // Supprime l’ancien tableau
        _size = other._size; // Copie la taille
        _array = new T[_size]; // Alloue un nouveau tableau
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = other._array[i]; // Copie chaque élément
        }
    }
    return *this; // Renvoie la référence à l'objet courant
}

// Surcharge de l’opérateur [] : accès en lecture/écriture à un élément
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) // Vérifie si l’index est valide
        throw std::out_of_range("Index out of bounds");
    return _array[index]; // Renvoie l’élément correspondant
}

// Version const : accès en lecture uniquement
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) // Vérifie si l’index est valide
        throw std::out_of_range("Index out of bounds");
    return _array[index]; // Renvoie l’élément correspondant
}

// Fonction membre size() : retourne la taille actuelle du tableau
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}