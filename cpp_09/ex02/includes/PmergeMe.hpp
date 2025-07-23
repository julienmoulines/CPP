#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
private:
    PmergeMe();                                // Canonical
    PmergeMe(const PmergeMe& other);           // Canonical
    PmergeMe& operator=(const PmergeMe& other); // Canonical
    ~PmergeMe();                               // Canonical

public:
    static bool IsPositive(const std::string& arg);
    static int toInt(const std::string& str);

    static void sortVector(std::vector<int>& vec);
    static void sortDeque(std::deque<int>& dq);
};

#endif
