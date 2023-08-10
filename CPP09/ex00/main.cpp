#include "BitcoinExchange.hpp"

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
        if (BitcoinExchange::validDate(date) == false)
            continue;
        std::getline(ss, price, ' ');
        if (line[11] != '|' || line.length()<14)
        {
            std::cerr << "Error: invalid file format" << std::endl;
            return (1);
        }
        std::getline(ss, price, ' ');
        if (price.find_first_not_of("+-0123456789.") != std::string::npos || price.empty() || !BitcoinExchange::validDouble(price))
        {
            std::cerr << "Error: invalid price" << std::endl;
            continue;
        }
        if(price[0] == '-')
        {
            std::cout<<"Error: not a positive number."<<std::endl;
            continue;
        }
        if (std::atof(price.c_str()) > 1000)
        {
            std::cout<<"Error: too large a number."<<std::endl;
            continue;
        }
        std::cout<<date<<" => "<<price<< " = "<< exchange.ExchangeRate(date) * std::atof(price.c_str())<<std::endl;
    }
    file.close();
    return 0;
}