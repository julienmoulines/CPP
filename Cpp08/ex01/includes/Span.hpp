#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <string>
#include <iostream>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _data;
	
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

# endif