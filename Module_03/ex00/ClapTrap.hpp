#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap 
{
	private:
		std::string _name;         
		int _hitPoints;            
		int _energyPoints;         
		int _attackDamage;         

	public:
		ClapTrap(); // Constructeur par défaut
		ClapTrap(std::string name); // Constructeur avec nom
		ClapTrap(const ClapTrap &other); // Constructeur de recopie
		ClapTrap& operator=(const ClapTrap &other); // Opérateur d'affectation
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



#endif