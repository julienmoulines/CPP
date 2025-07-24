#include "../includes/Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::~Span() {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

void	Span::addNumber(int number){
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is Full");
	_data.push_back(number);
}

// on trie le tableau puis on compare la difference entre chaque paire consecutive
int		Span::shortestSpan() const{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> temp = _data;
	std::sort(temp.begin(), temp.end());
	
	int min;
	int max;
	size_t i = 2;
	min = temp[1] - temp[0];
	while (i < temp.size())
	{
		max = temp[i] - temp[i - 1];
		if (max < min)
			min = max;
		i++;
	}
	return min;
}

int		Span::longestSpan() const{
	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());
	return (max - min);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_data.size() + std::distance(begin, end) > _maxSize)
        throw std::runtime_error("Not enough space to add the full range");
    _data.insert(_data.end(), begin, end);
}
