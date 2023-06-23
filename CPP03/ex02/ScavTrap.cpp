/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:22:44 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:08:54 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout<< "Scavtrap default constructor called"<<std::endl;
    setHitPoint(100);
    setEnergy(50);
    setAttackDamage(20);
}
ScavTrap::ScavTrap(std::string name)
{
    std::cout<< "Scavtrap constructor called"<<std::endl;
    setName(name);
    setHitPoint(100);
    setEnergy(50);
    setAttackDamage(20);
}

ScavTrap::~ScavTrap(){
     std::cout<< "Scavtrap distructor called"<<std::endl;
}
 ScavTrap::ScavTrap(ScavTrap &copy)
 {
    std::cout<< "Scavtrap copy constructor called"<<std::endl;
    *this = copy;
 }

 ScavTrap & ScavTrap::operator=( ScavTrap &copy){
    
    std::cout<< "ScavTrap copy assignement operator called"<<std::endl;
    if (this !=&copy)
    {
        this->setName(copy.getName());
        this->setAttackDamage(copy.getAttackDamage());
        this->setHitPoint(copy.getHitPoint());
        this->setEnergy(copy.getEnergy());
    }
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout <<"ScavTrap "<<getName()<<" is now in Gate keeper mode"<<std::endl;
}