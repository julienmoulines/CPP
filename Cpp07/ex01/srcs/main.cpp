#include "../includes/Iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void printElement(const T& elem) {
	std::cout << elem << std::endl;
}

template<typename T>
void increment(T& elem) {
	elem += 1;
}

void printCharUpper(char& c) {
	c = std::toupper(c);
	std::cout << c << " ";
}

int main() {
	std::cout << "===== INT array =====" << std::endl;
	int intArray[5] = {1, 2, 3, 4, 5};
	Iter(intArray, 5, printElement<int>);
	Iter(intArray, 5, increment<int>);
	Iter(intArray, 5, printElement<int>);

	std::cout << "\n===== FLOAT array =====" << std::endl;
	float floatArray[3] = {1.1f, 2.2f, 3.3f};
	Iter(floatArray, 3, printElement<float>);

	std::cout << "\n===== CHAR array =====" << std::endl;
	char charArray[4] = {'a', 'b', 'c', 'd'};
	Iter(charArray, 4, printCharUpper);
	std::cout << std::endl;

	std::cout << "===== STRING array =====" << std::endl;
	std::string strArray[3] = {"Hello", "World", "42"};
	Iter(strArray, 3, printElement<std::string>);

	std::cout << "\n===== CONST INT array =====" << std::endl;
	const int constArray[3] = {10, 20, 30};
	Iter(constArray, 3, printElement<int>);


	return 0;
}