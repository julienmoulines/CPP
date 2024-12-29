#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== TEST 1: Création d'un ScavTrap ===\n";
    // Création d'un ScavTrap, vérification des messages du constructeur
    ScavTrap scavTrap1("Serena");
    std::cout << "==========================\n";
    
    std::cout << "=== TEST 2: Attaque avec un ScavTrap ===\n";
    // Attaque avec un ScavTrap
    scavTrap1.attack("Target1");
    std::cout << "==========================\n";
    
    std::cout << "=== TEST 3: Réparation d'un ScavTrap ===\n";
    // Réparation avec un ScavTrap
    scavTrap1.beRepaired(30);
    std::cout << "==========================\n";

    std::cout << "=== TEST 4: Prise de dégât d'un ScavTrap ===\n";
    // ScavTrap prend des dégâts
    scavTrap1.takeDamage(50);
    std::cout << "==========================\n";
    
    std::cout << "=== TEST 5: Passage en mode 'Gate keeper' ===\n";
    // Appel de la fonction guardGate()
    scavTrap1.guardGate();
    std::cout << "==========================\n";
    
    std::cout << "=== TEST 6: Copie d'un ScavTrap ===\n";
    // Test de la copie d'un ScavTrap
    ScavTrap scavTrap2 = scavTrap1;
    scavTrap2.attack("Target2");
    std::cout << "==========================\n";
    
    std::cout << "=== TEST 7: Affectation d'un ScavTrap ===\n";
    // Test de l'opérateur d'affectation
    ScavTrap scavTrap3("NewScav");
    scavTrap3 = scavTrap1;
    scavTrap3.attack("Target3");
    std::cout << "==========================\n";

    std::cout << "=== TEST 8: Destruction d'un ScavTrap ===\n";
    // Destruction d'un ScavTrap, vérification des messages du destructeur
    {
        ScavTrap scavTrap4("TestDestruction");
    }
    std::cout << "==========================\n";
    
    return 0;
}
