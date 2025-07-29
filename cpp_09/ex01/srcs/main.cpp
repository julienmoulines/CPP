#include "../includes/RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error\n";
        return 1;
    }

    try {
        int result = RPN::evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/*
    Notation Polonaise Inversée (RPN) - Synthèse

    La notation polonaise inversée (Reverse Polish Notation) est une façon d’écrire
    les expressions mathématiques sans parenthèses ni priorité implicite.

    Principe :
        - Les opérandes sont placés AVANT l’opérateur.
        - Exemple classique : 
            Infixe classique  : 3 + 4
            RPN (postfixée)   : 3 4 +

        - Plus complexe :
            Infixe            : (3 + 4) * 5
            RPN               : 3 4 + 5 *

    Avantages :
        - Pas besoin de parenthèses : l’ordre est implicite.
        - Facile à évaluer avec une pile (stack).
        - Très utilisé en programmation bas-niveau, parseurs, compilateurs.

    Évaluation (algorithme) :
        - Lire l'expression de gauche à droite :
            • Si c’est un nombre → on le pousse dans la pile.
            • Si c’est un opérateur → on pop 2 éléments, on applique l’opération,
              et on push le résultat.
        - À la fin, la pile doit contenir exactement 1 élément : le résultat final.

    Exemple :
        Expression : 2 3 4 * +
        Étapes :
            - Push 2
            - Push 3
            - Push 4
            - '*' → 3 * 4 = 12 → push 12
            - '+' → 2 + 12 = 14 → push 14
        Résultat final : 14

    Utilisation classique :
        - Calculatrices HP
        - Langages comme PostScript, Forth
        - Compilation/interprétation d’expressions arithmétiques
*/