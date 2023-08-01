#include "BitcoinExchange.hpp"

bool validDate(std::string date){
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        return false;
    if (std::atof(month.c_str()) > 12 || std::atof(month.c_str()) < 1)
        return false;
    if (std::atof(day.c_str()) > 31 || std::atof(day.c_str()) < 1)
        return false;
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
        if (!validDate(date))
        {
            std::cerr << "Error: invalid date" << std::endl;
            return (1);
        }
        std::getline(ss, price, ' ');
        if (line[11] != '|' || line.length()<14)
        {
            std::cerr << "Error: invalid file format" << std::endl;
            return (1);
        }
        std::getline(ss, price, ' ');
        if (price.find_first_not_of("+-0123456789.") != std::string::npos || price.empty() || !validDouble(price))
        {
            std::cerr << "Error: invalid price" << std::endl;
            return (1);
        }
        exchange.addPrice(date, std::atof(price.c_str()));
        
    }
    return 0;
}