#include <iostream>
#include <vector>
#include <list>
#include "../includes/EasyFind.hpp"

int main() {
    std::vector<int> int_vec;
    int_vec.push_back(1);
    int_vec.push_back(22);
    int_vec.push_back(43);

    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(1337);
	lst.push_front(1);
	
    try {
		std::cout << std::endl << "------" << "Vector" << "------" << std::endl << std::endl;
        std::vector<int>::iterator it = easyfind(int_vec, 1);
        std::cout << "vec: valeur trouvée: " << *it << std::endl;
		it = easyfind(int_vec, 22);
        std::cout << "vec: valeur trouvée: " << *it << std::endl;
		it = easyfind(int_vec, 43);
        std::cout << "vec: valeur trouvée: " << *it << std::endl;
		it = easyfind(int_vec, 46);
        std::cout << "vec: valeur trouvée: " << *it << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << "vec: erreur: " << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
		std::cout << std::endl << "----" << "List" << "----" << std::endl << std::endl;
		std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "lst: valeur trouvée: " << *it << std::endl;
		it = easyfind(lst, 1337);
        std::cout << "lst: valeur trouvée: " << *it << std::endl;
		it = easyfind(lst, 1);
        std::cout << "lst: valeur trouvée: " << *it << std::endl;
        it = easyfind(lst, 0);
        std::cout << "lst: valeur trouvée: " << *it << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << "lst: erreur: " << e.what() << std::endl;
    }

    return 0;
}
