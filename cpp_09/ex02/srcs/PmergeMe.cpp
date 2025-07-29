#include "../includes/PmergeMe.hpp"

bool PmergeMe::IsPositive(const std::string& arg) {
    if (arg.empty()) return false;
    for (size_t i = 0; i < arg.length(); ++i) {
        if (!std::isdigit(arg[i]))
            return false;
    }
    return true;
}

int PmergeMe::toInt(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

// retourne un vecteur contenant dans quel ordre on doit insérer les éléments “minimums” dans le tableau trié
std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t size) {
    std::vector<size_t> indices;
    std::vector<size_t> jacob;  // Début de la suite de Jacobsthal
    jacob.push_back(0);
    jacob.push_back(1);
    //On génère la suite de Jacobsthal : 0, 1, 3, 5, 11, 21, ... jusqu’à >= size
    for (size_t i = 2;; ++i) {
        size_t next = jacob[i - 1] + 2 * jacob[i - 2];
        if (next >= size)
            break;
        jacob.push_back(next);
    }

    // Insertion dans l’ordre Jacobsthal inverse
    std::vector<bool> inserted(size, false);
    for (size_t i = jacob.size() - 1; i >= 1; --i) {
        size_t idx = jacob[i];
        if (idx < size && !inserted[idx]) {
            indices.push_back(idx); // Ajoute à l’ordre d’insertion
            inserted[idx] = true; // Marque comme inséré
        }
        if (i == 1)
            break;
    }
    // Ajouter les indices oubliés par jacobsthal à la fin
    for (size_t i = 0; i < size; ++i) {
        if (!inserted[i])
            indices.push_back(i); 
    }

    return indices;
}

// Insertion dans un vector trié
void PmergeMe::insertSorted(std::vector<int>& sorted, int value) {
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

// Insertion dans un deque trié
void PmergeMe::insertSorted(std::deque<int>& sorted, int value) {
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() < 2)
        return;

    std::vector<int> maxs, mins;
    // separation en paires (min max) [8, 3, 5, 2] = 3 2 |  8 5
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1]) {
            mins.push_back(vec[i]);
            maxs.push_back(vec[i + 1]);
        } else {
            mins.push_back(vec[i + 1]);
            maxs.push_back(vec[i]);
        }
    }

    bool odd = (vec.size() % 2 != 0); //On teste si le vecteur a une taille impaire.
    int leftover = odd ? vec.back() : -1; //leftover = (si odd est vrai) ? alors vec.back() : sinon -1;


    fordJohnsonSort(maxs); //trie recursif sur les max

    // On récupère l’ordre dans lequel on doit insérer les mins dans maxs
    std::vector<size_t> order = generateJacobsthalIndices(mins.size());
    //Insertion des mins dans maxs
    for (size_t i = 0; i < order.size(); ++i)
        insertSorted(maxs, mins[order[i]]);

    //si impaire rajouter l'element restant
    if (odd)
        insertSorted(maxs, leftover);
    // vec = version trié
    vec = maxs;
}

void PmergeMe::fordJohnsonSort(std::deque<int>& dq) {
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

    bool odd = (dq.size() % 2 != 0);
    int leftover = odd ? dq.back() : -1;

    fordJohnsonSort(maxs);

    std::vector<size_t> order = generateJacobsthalIndices(mins.size());
    for (size_t i = 0; i < order.size(); ++i)
        insertSorted(maxs, mins[order[i]]);

    if (odd)
        insertSorted(maxs, leftover);

    dq = maxs;
}

void PmergeMe::sortVector(std::vector<int>& vec) {
    fordJohnsonSort(vec);
}

void PmergeMe::sortDeque(std::deque<int>& dq) {
    fordJohnsonSort(dq);
}
