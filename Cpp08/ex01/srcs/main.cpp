#include "../includes/Span.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Partie 1 : exemple du sujet
    {
        std::cout << "--- Exemple du sujet ---" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Partie 2 : test avec 10000 valeurs et addRange
    {
        std::cout << "\n--- Test avec 10 000 valeurs ---" << std::endl;

        const int size = 10000;
        Span bigSpan(size);

        std::vector<int> buffer;
        buffer.reserve(size); //creaction et remplissage d'un container de la meme taille 

        std::srand(std::time(0)); // remplissage de valeurs aleatoires
        for (int i = 0; i < size; ++i)
            buffer.push_back(std::rand());

        try {
            bigSpan.addRange(buffer.begin(), buffer.end()); //remplissage de _data avec buffer 
            std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
            std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
			std::cout << "Add a 10 001 numbers: ";
			bigSpan.addNumber(15);
        } catch (std::exception& e) {
            std::cerr << "Erreur : " << e.what() << std::endl;
        }
    }

    return 0;
}
