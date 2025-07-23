#include "../includes/PmergeMe.hpp"


double getElapsed(struct timeval start, struct timeval end) {
    return (static_cast<double>(end.tv_sec - start.tv_sec)) * 1e6 + (static_cast<double>(end.tv_usec - start.tv_usec)); // en microsecondes
}

int main(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> dq;

	int i = 1;
	if (argc < 3){
		std::cout << "Error" << std::endl;
		return (1);
	}
	while (i < argc)
	{
		if (!PmergeMe::IsPositive(argv[i]))
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		vec.push_back(PmergeMe::toInt(argv[i]));
		dq.push_back(PmergeMe::toInt(argv[i]));
		i++;
	}

	std::vector<int> vecSorted = vec;
    std::deque<int> dqSorted = dq;

	struct timeval startVec, endVec, startDq, endDq;
    gettimeofday(&startVec, NULL);
    PmergeMe::sortVector(vecSorted);
    gettimeofday(&endVec, NULL);

    gettimeofday(&startDq, NULL);
    PmergeMe::sortDeque(dqSorted);
    gettimeofday(&endDq, NULL);

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
    	std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
    for (size_t i = 0; i < vecSorted.size(); ++i)
        std::cout << vecSorted[i] << " ";
    std::cout << std::endl;

	double timeVec = getElapsed(startVec, endVec);
    double timeDq = getElapsed(startDq, endDq);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us\n";
    std::cout << "Time to process a range of " << dq.size() << " elements with std::deque  : " << timeDq << " us\n";

    return 0;

}