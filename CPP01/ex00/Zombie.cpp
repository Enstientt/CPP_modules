/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:57:21 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/18 22:16:03 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
};

Zombie::~Zombie(void)
{
    std::cout << this->_name << " is dead" << std::endl;
};

void	Zombie::announce(void)
{
    std::cout<< this->_name <<" : BraiiiiiiinnnzzzZ..." << std::endl;
};