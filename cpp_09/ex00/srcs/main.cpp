#include "../includes/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

// 🔧 Fonction utilitaire : trim début et fin d'une string
std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        start++;
    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    try {
        BitcoinExchange btc("data.csv");

        std::ifstream input(argv[1]);
        if (!input.is_open()) {
            std::cerr << "Error: could not open file.\n";
            return 1;
        }

        std::string line;
        std::getline(input, line); // Skip header

        while (std::getline(input, line)) {
            if (line.empty())
                continue;

            size_t sep = line.find('|');
            if (sep == std::string::npos) {
                std::cerr << "Error: bad input => " << line << "\n";
                continue;
            }

            std::string date = trim(line.substr(0, sep));
            std::string valueStr = trim(line.substr(sep + 1));

            if (!BitcoinExchange::isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << "\n";
                continue;
            }

            std::stringstream ss(valueStr);
            float value;
            ss >> value;

            if (ss.fail() || !ss.eof()) {
                std::cerr << "Error: invalid value.\n";
                continue;
            }
            if (value < 0.0f) {
                std::cerr << "Error: not a positive number.\n";
                continue;
            }
            if (value > 1000.0f) {
                std::cerr << "Error: too large a number.\n";
                continue;
            }

            try {
                float rate = btc.getRateForDate(date);
                std::cout << date << " => " << value << " = " << value * rate << "\n";
            } catch (const std::exception& e) {
                std::cerr << e.what() << "\n";
            }
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
