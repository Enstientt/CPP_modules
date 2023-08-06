#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

class BitcoinExchange{
    private :
        std::map<int, float> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange &operator=(BitcoinExchange const &rh);
        void addPrice(int date, float price);
        std::map<int, float> getData() const {return this->_data;};
        float ExchangeRate(std::string date);
        ~BitcoinExchange();
    int compareStr(std::string str1, std::string str2);
    int calculateDaysSinceEpoch(const std::string& date);
    static bool validDate(std::string date);
    void validateData();
    static bool validDouble(std::string price);
};
#endif