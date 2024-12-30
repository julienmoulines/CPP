#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

	std::cout << "Dog type is : " << dog->getType() << std::endl;
	std::cout << "Cat type is : " << cat->getType() << std::endl;
    dog->makeSound(); // Appelle Dog::makeSound()
    cat->makeSound(); // Appelle Cat::makeSound()
    meta->makeSound(); // Appelle Animal::makeSound()

    delete cat;
    delete dog;
    delete meta;

    std::cout << "----- WrongAnimal Tests -----" << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Appelle WrongAnimal::makeSound() car pas virtual
    wrongMeta->makeSound(); // Appelle WrongAnimal::makeSound()
	// Utilisation directe de l'objet WrongCat
    const WrongCat *actualWrongCat = new WrongCat();
    actualWrongCat->makeSound(); // Appelle WrongCat::makeSound()

    delete wrongCat;
    delete wrongMeta;
	delete actualWrongCat;
	
    return 0;
}
