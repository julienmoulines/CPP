#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(){
    std::cout << "FragTrap Default "  << " is ready for war!" << std::endl;
}

// Constructeur
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " is ready for war!" << std::endl;
}

// Constructeur de recopie
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << this->_name << " copied!" << std::endl;
}

// Opérateur d'affectation
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // Appel de l'opérateur d'affectation de ClapTrap
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "FragTrap " << this->_name << " assigned!" << std::endl;
    return *this;
}

// Destructeur
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " destroyed in peace!" << std::endl;
}

// Méthode d'attaque
void FragTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "FragTrap " << this->_name << " jump on " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << "FragTrap " << this->_name << " has no energy or health to attack!" << std::endl;
    }
}

// Méthode highFivesGuys
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}
