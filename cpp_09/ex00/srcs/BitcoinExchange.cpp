#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    loadData(filename);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);
        std::stringstream ss(rateStr); //creer un flux de chaine pour extraire les possibles float
        float rate;
        ss >> rate;
        if (ss.fail())
            continue;
        _data[date] = rate;
    }
}


//it first = data.csv->date
//it->second = data.csv->rate
float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    // lower_bound retourne un itérateur vers le premier élément dont la clé n’est pas inférieure à key (ici dans le parsing de data.csv).
    if (it != _data.end() && it->first == date)
        return it->second;
    if (it == _data.begin())
        throw std::runtime_error("Error: no earlier date available.");
    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    // format YYYY-MM-DD, basique
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) {
    std::stringstream ss(valueStr);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        return false;
    return value >= 0.0f && value <= 1000.0f;
}
