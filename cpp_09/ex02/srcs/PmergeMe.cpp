#include "../includes/PmergeMe.hpp"

// Constructeur privé - interdit la création d’objets de cette classe (tout est statique)
PmergeMe::PmergeMe() {}

// Constructeur par copie (non utilisé, requis par la forme canonique)
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

// Opérateur d’affectation (non utilisé, requis par la forme canonique)
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

// Destructeur (non utilisé, requis par la forme canonique)
PmergeMe::~PmergeMe() {}


// Vérifie si une chaîne contient uniquement des chiffres → donc un entier positif
bool PmergeMe::IsPositive(const std::string& arg) {
    if (arg.empty()) return false;
    for (size_t i = 0; i < arg.length(); ++i) {
        if (!std::isdigit(arg[i]))
            return false;
    }
    return true;
}

// Convertit une chaîne de caractères en entier (utilise stringstream)
int PmergeMe::toInt(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}


// Insère une valeur dans un std::vector trié à la bonne position (binary search + insert)
static void insertSorted(std::vector<int>& sorted, int value) {
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}


// Trie un std::vector<int> en utilisant l’algorithme Ford-Johnson (merge-insert sort)
void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() < 2)
        return;

    std::vector<int> maxs, mins;

    // Étape 1 : former des paires et séparer les mins et maxs
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1]) {
            mins.push_back(vec[i]);
            maxs.push_back(vec[i + 1]);
        } else {
            mins.push_back(vec[i + 1]);
            maxs.push_back(vec[i]);
        }
    }

    // Si nombre impair d’éléments, on ajoute le dernier dans mins
    if (vec.size() % 2 != 0)
        mins.push_back(vec.back());

    // Étape 2 : tri récursif des maximums
    sortVector(maxs);

    // Étape 3 : insertion des minimums un à un dans le vecteur trié
    for (size_t i = 0; i < mins.size(); ++i)
        insertSorted(maxs, mins[i]);

    // Le vecteur trié devient la version finale
    vec = maxs;
}


// Insère une valeur dans un std::deque trié à la bonne position (équivalent à vector)
static void insertSorted(std::deque<int>& sorted, int value) {
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}


// Même chose que sortVector mais avec un std::deque<int>
void PmergeMe::sortDeque(std::deque<int>& dq) {
    if (dq.size() < 2)
        return;

    std::deque<int> maxs, mins;

    for (size_t i = 0; i + 1 < dq.size(); i += 2) {
        if (dq[i] < dq[i + 1]) {
            mins.push_back(dq[i]);
            maxs.push_back(dq[i + 1]);
        } else {
            mins.push_back(dq[i + 1]);
            maxs.push_back(dq[i]);
        }
    }

    if (dq.size() % 2 != 0)
        mins.push_back(dq.back());

    sortDeque(maxs);

    for (size_t i = 0; i < mins.size(); ++i)
        insertSorted(maxs, mins[i]);

    dq = maxs;
}
