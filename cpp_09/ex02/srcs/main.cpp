#include "../includes/PmergeMe.hpp"

//  Calcul du temps écoulé (en microsecondes)
double getElapsed(struct timeval start, struct timeval end) {
    return (static_cast<double>(end.tv_sec - start.tv_sec)) * 1e6 + 
           (static_cast<double>(end.tv_usec - start.tv_usec));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> dq;

    //  Parsing et vérification
    for (int i = 1; i < argc; ++i) {
        if (!PmergeMe::IsPositive(argv[i])) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int val = PmergeMe::toInt(argv[i]);
        vec.push_back(val);
        dq.push_back(val);
    }

    //  Mesure du temps pour vector
    std::vector<int> sortedVec = vec;
    struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);
    PmergeMe::sortVector(sortedVec);
    gettimeofday(&endVec, NULL);

    //  Mesure du temps pour deque
    std::deque<int> sortedDq = dq;
    struct timeval startDq, endDq;
    gettimeofday(&startDq, NULL);
    PmergeMe::sortDeque(sortedDq);
    gettimeofday(&endDq, NULL);

    //  Affichage
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "After:  ";
    for (size_t i = 0; i < sortedVec.size(); ++i)
        std::cout << sortedVec[i] << " ";
    std::cout << std::endl;

    double timeVec = getElapsed(startVec, endVec);
    double timeDq = getElapsed(startDq, endDq);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us\n";
    std::cout << "Time to process a range of " << dq.size()  << " elements with std::deque  : " << timeDq << " us\n";

    return 0;
}



// sépare les paires en minim et maxim, trie récursivement les maxim, et insère les minim dans un ordre défini par la séquence de Jacobsthal pour minimiser les comparaisons
// garantit une complexité proche de O avec un nombre de comparaisons optimal pour les petites tailles.