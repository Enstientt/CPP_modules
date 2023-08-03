#include "BitcoinExchange.hpp"

bool validDate(std::string date){
    if (date.length() != 10)
    {
        std::cout << "Error: bad input => "<<date << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => "<<date << std::endl;
        return false;
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
    {
        std::cout << "Error: bad input => "<<date << std::endl;
        return false;
    }
    if (std::atof(month.c_str()) > 12 || std::atof(month.c_str()) < 1)
    {
        std::cout << "Error: bad input => "<<date << std::endl;
        return false;
    }
    int day1 = std::atof(day.c_str());
    int year1 = std::atof(year.c_str());
    int month1 = std::atof(month.c_str());
    if ((month1==2 && year1%4==0 && (day1 > 29 || day1 < 1))
        || (month1==2 && year1%4!=0 && (day1 > 28 || day1 < 1)))
    {
        std::cout << "Error: bad input => "<<date << std::endl;
        return false;
    }

    if ((month1%2==1 &&(day1 > 31 || day1 < 1)) || (month1%2==0 &&(day1 > 30 || day1 < 1)))
    {
        std::cout << "Error: bad input => "<<date << std::endl;
        return false;
    }
    return true;
}

bool validDouble(std::string price){
    int dout = 0;
    for (size_t i = 0; i < price.length(); i++){
        if (i == 0 && (price[i] == '-' || price[i] == '+' ))
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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return (1);
    }
    std::string line;
    BitcoinExchange exchange;
    std::getline(file, line);
    if (line != "date | value")
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return (1);
    }
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string date;
        std::string price;
        std::getline(ss, date, ' ');
        if (validDate(date) == false)
            continue;
        std::getline(ss, price, ' ');
        if (line[11] != '|' || line.length()<14)
        {
            std::cerr << "Error: invalid file format" << std::endl;
            continue;
        }
        std::getline(ss, price, ' ');
        if (price.find_first_not_of("+-0123456789.") != std::string::npos || price.empty() || !validDouble(price))
        {
            std::cerr << "Error: invalid price" << std::endl;
            continue;
        }
        if(price[0] == '-')
        {
            std::cout<<"Error: not a positive number."<<std::endl;
            continue;
        }
        if (std::atof(price.c_str()) >= 2147483648)
        {
            std::cout<<"Error: too large a number."<<std::endl;
            continue;
        }
        std::cout<<date<<" => "<<price<< " = "<< exchange.ExchangeRate(date)<<std::endl;
    }
    file.close();
    return 0;
}