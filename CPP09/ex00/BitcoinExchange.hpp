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
        std::map<std::string, float> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange &operator=(BitcoinExchange const &rh);
        void addPrice(std::string date, float price);
        std::map<std::string, float> getData() const {return this->_data;};
        float ExchangeRate(std::string date) const;
        ~BitcoinExchange();
    static int compare(std::string str1, std::string str2);
};
#endif