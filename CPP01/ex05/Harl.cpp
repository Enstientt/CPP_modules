/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:46:36 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/19 14:05:11 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string level) : _level(level)
{
};

Harl::~Harl(void)
{
};

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;    
};

void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<< std::endl;
};

void Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;    
};

void Harl::complain(std::string level)
{
    void (Harl::*f[4])(void) = {&Harl::_debug, &Harl::_warning, &Harl::_info, &Harl::_error};
    std::string levels[4] = {"debug", "warning", "info", "error"};
    int i = 0;
    while (i < 4)
    {
        if (level == levels[i])
            (this->*f[i])();
        i++;
    }
};   
