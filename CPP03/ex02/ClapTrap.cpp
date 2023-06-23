/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:37:18 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:11:17 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap :: ClapTrap(): _hitPoint(10) , _energy(10) , _attackDamage(0){
           std::cout << "the ClapTrap default constructor is called "<<std::endl;
}
ClapTrap :: ClapTrap(std::string name): _name(name), _hitPoint(10) , _energy(10) , _attackDamage(0) {
    std::cout << "the ClapTrap constructor is called "<<std::endl;
}

ClapTrap ::~ClapTrap(){
    std::cout<< "the ClapTrap distructor is called"<<std::endl;
}

ClapTrap :: ClapTrap(ClapTrap & copy)
{
    std::cout<< "ClapTrap copy constructor called"<<std::endl;
    *this = copy;
}
void  ClapTrap::attack(const std:: string& target){
    if (this->_energy > 0 && this->_hitPoint > 0 )
    {
        std::cout<<"ClapTrap "<< _name<< " attacks "<< target<<" , causing "<< _attackDamage<<"  points of damage!"<<std::endl;
        _energy -=1;
    }
    else
        std::cout << "no more energy or hit points left for  " << _name<<std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap &copy){
    
    std::cout<< "copy assignement operator called"<<std::endl;
    if (this !=&copy)
    {
        this->_name = copy._name;
        this->_attackDamage = copy._attackDamage;
        this-> _hitPoint = copy._hitPoint;
        this->_energy = copy._energy;
    }
    return (*this);
}
void ClapTrap::takeDamage(unsigned int amount){
    if (this->_energy > 0 && this->_hitPoint > 0 )
    {
        std::cout<<"ClapTrap "<< _name<<" takes "<<amount<<" points of damage!"<<std::endl;
        _hitPoint -= amount;
    }
    else
        std::cout << "no more energy or hit points left for  " << _name<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energy > 0 && this->_hitPoint > 0 )
    {
        std::cout<<"ClapTrap "<< _name<<" takes a recovery of "<<amount<<" points!"<<std::endl;
        this->_hitPoint += amount;
        this->_energy -= 1;
    }
    else
        std::cout << "no more energy or hit points left for " << _name<<std::endl;
}


  std::string ClapTrap::getName() const 
{
    return this->_name;
}

 int ClapTrap:: getAttackDamage() const 
{
    return this->_attackDamage;
}

int ClapTrap::getHitPoint() const
{
    return this->_hitPoint;
}

int ClapTrap::getEnergy() const
{
    return this->_energy;
}

void ClapTrap::setAttackDamage(int attackDamage){
    this->_attackDamage = attackDamage;
}

void ClapTrap::setEnergy(int energy){
    this->_energy = energy;
}

void ClapTrap::setHitPoint(int hitPoint){
    this->_hitPoint = hitPoint;
}

void ClapTrap::setName(std::string name){
    this->_name = name;
}