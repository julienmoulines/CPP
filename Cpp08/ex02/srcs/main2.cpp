#include "../includes/MutanStack.hpp"
#include <iostream>
#include <list>

void printHeader(const std::string& title) {
    std::cout << "\n===== " << title << " =====" << std::endl;
}

int main() {
    printHeader("Test avec MutantStack");
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack); // test de compatibilité std::stack

    printHeader("Test équivalent avec std::list");

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
