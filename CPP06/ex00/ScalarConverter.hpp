/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:43:52 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/28 13:25:51 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
    public:
        static void    convert(std::string param);
        static bool    isSpecialFloat(const std::string& param);
        static bool    isSpecialDouble(const std::string& param);
        static bool    isChar(const std::string& param);
        static bool    isFloat(const std::string& param);
        static bool    isDouble(const std::string& param);
        static void    handleSpecialFloat(const std::string& param);
        static void    handleSpecialDouble(const std::string& param);
        static void    handleChar(const std::string& param);
        static void    handleFloat(const std::string& param);
        static void    handleDouble(const std::string& param);
        static void    handleInt(const std::string& param);
};

#endif