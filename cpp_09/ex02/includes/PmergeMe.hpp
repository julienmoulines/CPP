#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <algorithm> // Pour std::lower_bound

class PmergeMe {
private:
    PmergeMe();                                
    PmergeMe(const PmergeMe&);                 
    PmergeMe& operator=(const PmergeMe&);      
    ~PmergeMe();                              

    // Génère les indices dans l’ordre Jacobsthal pour insertion optimisée
    static std::vector<size_t> generateJacobsthalIndices(size_t size);

    // Insertion dans un conteneur trié à la bonne position
    static void insertSorted(std::vector<int>& sorted, int value);
    static void insertSorted(std::deque<int>& sorted, int value);

    static void fordJohnsonSort(std::vector<int>& vec);
    static void fordJohnsonSort(std::deque<int>& dq);

public:
    static bool IsPositive(const std::string& arg);  
    static int toInt(const std::string& str);        

    static void sortVector(std::vector<int>& vec);  
    static void sortDeque(std::deque<int>& dq);    
};

#endif
