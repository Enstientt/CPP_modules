/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:25 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:13:00 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout<< "FragTrap default constructor called"<<std::endl;
    this->setHitPoint(100);
    this->setEnergy(100);
    this->setAttackDamage(30);
}
FragTrap::FragTrap(std::string name)
{
    std::cout<< "FragTrap constructor called"<<std::endl;
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergy(100);
    this->setAttackDamage(30);
}

FragTrap::~FragTrap(){
     std::cout<< "FragTrap distructor called"<<std::endl;
}
 FragTrap::FragTrap(FragTrap &copy)
 {
    std::cout<< "FragTrap copy constructor called"<<std::endl;
    *this = copy;
 }

 FragTrap & FragTrap::operator=( FragTrap &copy){
    
    std::cout<< "FragTrap copy assignement operator called"<<std::endl;
    if (this !=&copy)
    {
        this->setName(copy.getName());
        this->setAttackDamage(copy.getAttackDamage());
        this->setHitPoint(copy.getHitPoint());
        this->setEnergy(copy.getEnergy());
    }
    return (*this);
}

void FragTrap::highFivesGuys(void){
    std::cout<<"FragTrap "<< this->getName()<< ": 🙏  🙏 " <<std::endl;
}