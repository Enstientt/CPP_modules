#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <string.h>

BitcoinExchange::BitcoinExchange(){
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

void  BitcoinExchange::addPrice(int date, float price){
    this->_data.insert(std::pair<int, float>(date, price)); 
}

float BitcoinExchange::ExchangeRate(std::string date) {
    // int found = 0;
    std::ifstream file("data.csv");
    std::string line;
    std::string date1;
    std::string price;
    this->_data.clear();
    // std::string date2;
    // std::string price2;
    //std::getline(file, line);
    // while (std::getline(file, line))
    // {
    //     if (line.empty())
    //         continue;
    //     std::stringstream ss(line);
    //     std::getline(ss, date1, ',');
    //     std::getline(ss, price, ',');
    //     std::getline(ss, date2, ',');
    //     std::getline(ss, price2, ',');
    //     if (date1 == date)
    //         return std::atof(price.c_str());
    // }
    // std::ifstream file1("data.csv");
    std::getline(file, line);
    int min = 0;
     while (std::getline(file, line))
    {
        std::stringstream sss(line);
        std::getline(sss, date1, ',');
        std::getline(sss, price, ',');
        min = compareStr(date, date1);
        if (min >= 0){
            addPrice(min, std::atof(price.c_str()));
        }
        else
            break;
    }
    // for(std::map<int, float>::iterator it = _data.begin(); it != _data.end(); ++it){
    //     std::cout << it->first << "===>" << it->second << std::endl;
    // }
    return _data.begin()->second;
}

int BitcoinExchange::compareStr(std::string date,std::string date2){
        int date1 = calculateDaysSinceEpoch(date);
        int datee2 = calculateDaysSinceEpoch(date2);
        int difference = date1 - datee2;
        return difference;
}
//  int compare(std::string date, std::string date2) {
//         int date1 = calculateDaysSinceEpoch(date);
//         int datee2 = calculateDaysSinceEpoch(date2);
//         int difference = std::abs(date1 - datee2);
//         return difference;
//     }
 int BitcoinExchange::calculateDaysSinceEpoch(const std::string& date) {
        int days = 0;
        std::string year = date.substr(0, 4);
        std::string month = date.substr(5, 2);
        std::string day = date.substr(8, 2);
        int year1 = std::atof(year.c_str());
        int month1 = std::atof(month.c_str());
        int day1 = std::atof(day.c_str());

        days += 365 * year1;
        days += (year1 / 4) - (year1 / 100) + (year1 / 400); // Adjust for leap years

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int m = 1; m < month1; ++m) {
            days += daysInMonth[m];
        }
        if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) {
            if (month1 > 2) {
                days += 1;
            }
        }
        days += day1;
        return days;
    }