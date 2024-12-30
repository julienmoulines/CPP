#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "\n========== CONSTRUCTION DE BASE ==========\n" << std::endl;

    // Test des constructeurs de base
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n========== TEST DES FONCTIONS DE BASE ==========\n" << std::endl;

    // Test des fonctions
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();

    std::cout << "\n========== DESTRUCTION DE BASE ==========\n" << std::endl;

    // Suppression des objets pour vérifier les destructeurs
    delete dog;
    delete cat;

    std::cout << "\n========== TEST DE COPIE PROFONDE ==========\n" << std::endl;

    // Test de la copie profonde
    Dog basicDog;
    {
        Dog tmpDog = basicDog; // Copie profonde
        std::cout << "End of scope, tmpDog will be destroyed." << std::endl;
    }

    std::cout << "\n========== TEST DE LA GESTION DE MÉMOIRE ==========\n" << std::endl;

    // Tableau d'objets Animal
    const size_t arraySize = 4; // 2 Dogs et 2 Cats
    std::vector<const Animal*> animals;

    std::cout << "Creating animals..." << std::endl;
    for (size_t i = 0; i < arraySize / 2; ++i) {
        animals.push_back(new Dog());
        animals.push_back(new Cat());
    }

    std::cout << "\nDestroying animals..." << std::endl;
    for (size_t i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

    std::cout << "\n========== TEST SANS DESTRUCTEUR VIRTUAL ==========\n" << std::endl;

    // Test du mot-clé virtual dans les destructeurs
    WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongAnimal sound: ";
    wrongAnimal->makeSound();

    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();

    delete wrongAnimal; // Appelle seulement WrongAnimal destructor si destructeurs non virtual
    delete wrongCat;    // Appelle seulement WrongAnimal destructor si destructeurs non virtual

    std::cout << "\n========== FIN DES TESTS ==========\n" << std::endl;

    return 0;
}
