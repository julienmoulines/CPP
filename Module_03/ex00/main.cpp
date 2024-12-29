#include "ClapTrap.hpp"

int main() {
    // Création d'un robot ClapTrap et d'un robot avec le constructeur par defaut
    ClapTrap robot("CL4P-TP");
	ClapTrap test;

    // Test des actions
    robot.attack("enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
	
	test.attack("enemy");
    test.takeDamage(5);
    test.beRepaired(3);


    // Simulation de fin de vie
    robot.takeDamage(10);
    robot.attack("enemy");
    robot.beRepaired(5);

	test.takeDamage(10);
    test.attack("enemy");
    test.beRepaired(5);


    return 0;
}
