#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <string.h>

BitcoinExchange::BitcoinExchange(){
    this->_data = std::map<std::string, float>();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy){
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rh){
    if (this != &rh)
        this->_data = rh._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
}

void BitcoinExchange::addPrice(std::string date, float price){
    this->_data.insert(std::pair<std::string, float>(date, price)); 
}

float BitcoinExchange::ExchangeRate(std::string date) const{
    int found = 0;
    std::ifstream file("data.csv");
    std::string line;
    std::string date1;
    std::string price;
    std::string date2;
    std::string price2;
    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return (1);
    }
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::getline(ss, date1, ',');
        std::getline(ss, price, ',');
        std::getline(ss, date2, ',');
        std::getline(ss, price2, ',');
        if (date1 == date)
            return std::stof(price);
    }
    std::ifstream file1("data.csv");
    std::getline(file1, line);
    std::map<int, float> tmp;
    int min = INT8_MAX;
     while (std::getline(file1, line))
    {
        std::stringstream sss(line);
        std::getline(sss, date1, ',');
        std::getline(sss, price, ',');
        if (compare(date, date1) < min && compare(date, date) > 0){
            min = compare(date, date1);
            tmp.insert(std::pair<int, float>(min, std::stof(price)));
        }
    }

}

int BitcoinExchange::compare(std::string str1, std::string str2){
    std::reverse(str1.begin(), str1.end());
    std::reverse(str2.begin(), str2.end());
    return str1.compare(str2);
}