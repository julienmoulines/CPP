#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    // Test de la création d'un ClapTrap
    std::cout << "\n=== Création d'un ClapTrap ===\n";
    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    clap.takeDamage(30);
    clap.beRepaired(20);

    // Test de la création d'un ScavTrap
    std::cout << "\n=== Création d'un ScavTrap ===\n";
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    // Test de la création d'un FragTrap
    std::cout << "\n=== Création d'un FragTrap ===\n";
    FragTrap frag("Fraggy");
    frag.attack("Enemy");
    frag.takeDamage(50);
    frag.beRepaired(40);
    frag.highFivesGuys();

    // Test de la construction et destruction d'un ScavTrap via copie
    std::cout << "\n=== Test de la copie d'un ScavTrap ===\n";
    ScavTrap scavCopy(scav); // Doit appeler le constructeur de recopie
    scavCopy.attack("Enemy");
    
    // Test de l'opérateur d'affectation
    std::cout << "\n=== Test de l'opérateur d'affectation ===\n";
    FragTrap frag2("Fraggy2");
    frag2 = frag; // Opérateur d'affectation
    frag2.attack("Enemy");

    // Test de la destruction des objets (affichage des messages de destruction)
    std::cout << "\n=== Destruction des objets ===\n";
    {
        FragTrap frag3("Fraggy3");
        frag3.attack("Enemy");
    } // La destruction de FragTrap doit être testée ici
    
    {
        ScavTrap scav2("Scavvy2");
        scav2.attack("Enemy");
    } // La destruction de ScavTrap doit être testée ici

    // La destruction de ClapTrap sera testée automatiquement lorsque "clap" sortira du scope.

    return 0;
}
