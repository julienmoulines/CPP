#include "../includes/MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;

    std::cout << "Test push() & top():\n";
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl; // 17

    std::cout << "\nTest pop() & size():\n";
    mstack.pop(); // retire 17
    std::cout << "Size: " << mstack.size() << std::endl; // 1
    std::cout << "Top: " << mstack.top() << std::endl; // 5


    std::cout << "\nAjout de plusieurs valeurs : 3, 5, 737, 0\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nTest de l'itération :\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "\nCopie de la stack vers std::stack :\n";
    std::stack<int> s(mstack);
    std::cout << "Top: " << mstack.top() << std::endl; // 0
    std::cout << "Top de la stack copiée : " << s.top() << std::endl;
		
    return 0;
}
