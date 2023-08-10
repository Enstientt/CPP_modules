#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    validateData();
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
    std::ifstream file("data.csv");
    std::string line;
    std::string date1;
    std::string price;
    this->_data.clear();
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
    return _data.begin()->second;
}

int BitcoinExchange::compareStr(std::string date,std::string date2){
        int date1 = calculateDays(date);
        int datee2 = calculateDays(date2);
        int difference = date1 - datee2;
        return difference;
}
 int BitcoinExchange::calculateDays(const std::string& date) {
        int days = 0;
        std::string year = date.substr(0, 4);
        std::string month = date.substr(5, 2);
        std::string day = date.substr(8, 2);
        int year1 = std::atof(year.c_str());
        int month1 = std::atof(month.c_str());
        int day1 = std::atof(day.c_str());

        days += 365 * year1;
        days += (year1 / 4) - (year1 / 100) + (year1 / 400);
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

    bool BitcoinExchange::validDate(std::string date)
{
    if (date.length() != 10)
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: bad input  => "<<date << std::endl;
            return false;
        }
    }
    for (int i = 5; i < 7; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: bad input  => "<<date << std::endl;
            return false;
        }
    }
    for (int i = 8; i < 10; i++)
    {
        if (!isdigit(date[i]))
        {
            std::cout << "Error: bad input  => "<<date << std::endl;
            return false;
        }
    }
    
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    if (std::atof(month.c_str()) > 12 || std::atof(month.c_str()) < 1)
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    int day1 = std::atof(day.c_str());
    int year1 = std::atof(year.c_str());
    int month1 = std::atof(month.c_str());
    if (year1 < 2009)
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    if ((month1==2 && year1%4==0 && (day1 > 29 || day1 < 1))
        || (month1==2 && year1%4!=0 && (day1 > 28 || day1 < 1)))
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }

    if ((month1==1 || month1==3 \
        || month1==5 || month1==7 \
        || month1==8 || month1==10 || month1==12)
        && (day1 > 31 || day1 < 1))
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    if((month1==4 || month1==6 \
        || month1==9 || month1==11) \
        && (day1 > 30 || day1 < 1))
    {
        std::cout << "Error: bad input  => "<<date << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::validateData(){
    std::ifstream file("data.csv");
    std::string line;
    std::string date;
    std::string price;
    std::getline(file, line);
    if (line !="date,exchange_rate")
    {
        std::cout << "Error: invalid data base format"<< std::endl;
        exit(1);
    }
    while (std::getline(file, line))
    {
        std::stringstream sss(line);
        std::getline(sss, date, ',');
        std::getline(sss, price, ',');
        if (!validDate(date))
            exit(1);
        if (!validDouble(price))
        {
            std::cout << "Error: bad input in the data base => "<<price << std::endl;
            exit(1);
        }
    }
}

bool BitcoinExchange::validDouble(std::string price){
    int dout = 0;
    for (size_t i = 0; i < price.length(); i++){
        if (i == 0 && (price[i] == '+' ))
            continue;
        if (price[i] == '.')
            dout++;
        if (dout > 1)
            return false;
        if (price[i] != '.' &&  (price[i] < '0' || price[i] > '9'))
            return false;
        
    }
    return true;
}