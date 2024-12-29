#include "ClapTrap.hpp"

// Constructeur par défaut
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called\n";
}

// Constructeur de recopie
ClapTrap::ClapTrap(const ClapTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap copy constructor called\n";
}

// Constructeur : initialise les attributs avec les valeurs données ou par défaut
ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

// Destructeur : affiche un message lorsqu'un objet est détruit
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// Opérateur d'affectation
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {  // On évite l'auto-affectation
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap assignment operator called\n";
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack because it has no energy or is destroyed!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    if (_hitPoints < 0) _hitPoints = 0; // Empêcher des points négatifs
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't repair because it has no energy or is destroyed!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
              << " hit points! Current HP: " << _hitPoints << std::endl;
}
