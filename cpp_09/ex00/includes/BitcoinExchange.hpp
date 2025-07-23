#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& filename);
    ~BitcoinExchange();

    float getRateForDate(const std::string& date) const;
    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& valueStr);

private:
    std::map<std::string, float> _data;
    void loadData(const std::string& filename);
	BitcoinExchange(BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange& other);
};

#endif
