/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:43:49 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:05 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

bool ScalarConverter::isSpecialFloat(const std::string& param)
{
    return (param == "-inff" || param == "+inff" || param == "nanf");
}

bool ScalarConverter::isSpecialDouble(const std::string& param)
{
    return (param == "inf" || param == "-inf" || param == "+inf" || param == "nan");
}

bool ScalarConverter::isChar(const std::string& param)
{
    return (param.length() == 3 && param[0] == 39 && param[param.length() - 1] == 39);
}

bool ScalarConverter::isFloat(const std::string& param)
{
    std::size_t found = param.find('f');
    return (param[param.length() - 1] == 'f' && found != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string& param)
{
    std::size_t found = param.find('.');
    return (found != std::string::npos);
}

void ScalarConverter::handleSpecialFloat(const std::string& param)
{
    std::cout << "char: Impossible\n";
    std::cout << "int: Impossible\n";
    
    if (param == "-inff")
    {
        float num = std::numeric_limits<float>::infinity() * -1;
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
    else if (param == "+inff")
    {
        float num = std::numeric_limits<float>::infinity();
        std::cout << "float: +" << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: +" << static_cast<double>(num) << std::endl;
    }
    else if (param == "nanf")
    {
        float num = std::numeric_limits<float>::quiet_NaN();
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
}

void ScalarConverter::handleSpecialDouble(const std::string& param)
{
    std::cout << "char: Impossible\n";
    std::cout << "int: Impossible\n";
    
    if (param == "-inf")
    {
        double num = std::numeric_limits<double>::infinity() * -1;
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
    else if (param == "+inf" || param == "inf")
    {
        double num = std::numeric_limits<double>::infinity();
        std::cout << "float: +" << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: +" << static_cast<double>(num) << std::endl;
    }
    else if (param == "nan")
    {
        double num = std::numeric_limits<double>::quiet_NaN();
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
}

void ScalarConverter::handleChar(const std::string& param)
{
    char c = param[1];

    if (!isprint(c) || c == ' ')
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::handleFloat(const std::string& param)
{
    float num =std::stof(param);
    int tmp = static_cast<int>(num);
     std::string  strf =  (round(num) - num == 0)? ".0f" : "f";
     std::string strd =  (round(num) - num == 0)? ".0" : "";
    (tmp >= 32 || tmp <128)? std::cout << "char: " << static_cast<char>(tmp) << std::endl : \
    std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    (param.find(".")== std::string::npos)?std::cout<<"float: "<< static_cast<float>(num) << ".0f" << std::endl: \
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::handleDouble(const std::string& param)
{
    double num = std::stod(param);
     int tmp = static_cast<int>(num);
     std::string  strf =  (round(num) - num == 0)? ".0f" : "f";
     std::string strd =  (round(num) - num == 0)? ".0" : "";
    (tmp >= 32 || tmp <128)? std::cout << "char: " << static_cast<char>(tmp) << std::endl : \
    std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << strf<< std::endl;
    std::cout << "double: " << static_cast<double>(num)<< strd << std::endl;
}

void ScalarConverter::handleInt(const std::string& param)
{
    int num = std::stoi(param);
    
    if (num < 32 || num > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::convert(std::string param)
{
    
    if (isSpecialFloat(param))
    {
        handleSpecialFloat(param);
        return;
    }

    else if (isSpecialDouble(param))
    {
        handleSpecialDouble(param);
        return;
    }

    else if (isChar(param))
    {
        handleChar(param);
        return;
    }

    else if (isFloat(param))
    {
        handleFloat(param);
        return;
    }

    else if (isDouble(param))
    {
        handleDouble(param);
        return;
    }

    handleInt(param);
}