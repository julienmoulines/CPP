#include <iostream>
#include <cstdlib>  // pour rand()
#include "../includes/Array.hpp"

#define SIZE 5

// Fonction pour imprimer tous les éléments de l'array
template <typename T>
void printArray(const Array<T>& arr) {
	std::cout << "[ ";
	for (unsigned int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}

int main() {
	std::cout << "✅ Test 1 : Constructeur par défaut (array vide)" << std::endl;
	Array<int> empty;
	std::cout << "Taille de l'array vide : " << empty.size() << std::endl;

	std::cout << "\n✅ Test 2 : Constructeur avec taille + remplissage" << std::endl;
	Array<int> arr(SIZE);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i * 10;  // Remplissage avec des valeurs connues
	printArray(arr);

	std::cout << "\n✅ Test 3 : Copie de l'array avec constructeur de copie" << std::endl;
	Array<int> copyArr(arr);
	std::cout << "Original : ";
	printArray(arr);
	std::cout << "Copie    : ";
	printArray(copyArr);

	std::cout << "\n✅ Test 4 : Modification d'une copie (test d'indépendance)" << std::endl;
	copyArr[0] = 999;
	std::cout << "Original après modif : ";
	printArray(arr);
	std::cout << "Copie modifiée       : ";
	printArray(copyArr);

	std::cout << "\n✅ Test 5 : Assignation d'un array" << std::endl;
	Array<int> assign;
	assign = arr;
	std::cout << "Assignation : ";
	printArray(assign);

	std::cout << "\n✅ Test 6 : Accès hors limites (négatif et trop grand)" << std::endl;
	try {
		std::cout << "arr[-1] = ";
		std::cout << arr[-1] << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	try {
		std::cout << "arr[SIZE] = ";
		std::cout << arr[SIZE] << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	std::cout << "\n✅ Test 7 : Vérification de size()" << std::endl;
	std::cout << "Taille actuelle de arr : " << arr.size() << std::endl;

	return 0;
}
