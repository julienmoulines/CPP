#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(av[i][j]));
		}
	}
	std::cout << std::endl;
	return 0;
}

/* 

#include <iostream> // Inclusion de la bibliothèque d'entrées/sorties standard en C++
#include <cctype>   // Inclusion de la bibliothèque pour les fonctions de manipulation de caractères

// La fonction principale du programme
int main(int ac, char **av)
{
    // Si aucun argument n'est fourni, affiche un message par défaut
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; // std::cout est l'équivalent de printf, utilisé pour afficher du texte
    else
    {
        // Boucle sur chaque argument (à partir de 1 car 0 est le nom du programme)
        for (int i = 1; av[i]; i++)
        {
            // Boucle sur chaque caractère de l'argument actuel
            for (int j = 0; av[i][j]; j++)
                // Affiche le caractère actuel en majuscule
                // std::toupper convertit un caractère en majuscule
                // static_cast<char> est utilisé pour assurer la conversion correcte en type char
                std::cout << static_cast<char>(std::toupper(av[i][j]));
        }
    }
    // Affiche un saut de ligne à la fin de la sortie
    std::cout << std::endl;

    // Retourne 0 pour indiquer que le programme s'est terminé avec succès
    return 0;
}

*/