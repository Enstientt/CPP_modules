/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:32:10 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 14:29:32 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
   // std::cout<<"Character default constructor called"<<std::endl;
    for(int i = 0;i<4;i++){
        this->materias[i] = NULL;
    }
}

Character::Character(std::string name){
   // std::cout<<"Character constructor called"<<std::endl;
    this->_name=name;
    for(int i = 0;i<4;i++){
        this->materias[i] = NULL;
    }
}

Character::Character(Character &copy){
    *this = copy;
}

 Character & Character::operator=(Character &copy){
    if (this!=&copy){
        this->_name = copy.getName();
        for(int i = 0;i<4;i++){
            if (this->materias[i])
            {
                delete this->materias[i];
                this->materias[i] = NULL;
            }
            this->materias[i] = copy.materias[i];
        }
    }
    return *this;
 }

Character::~Character(){
     //std::cout<<"Character disconstructor called"<<std::endl;
      for(int i = 0;i<4;i++){
        if (this->materias[i])
             delete this->materias[i];
        }
}

std::string const & Character::getName() const{
    return this->_name;
}

void Character::equip(AMateria* m){
    for(int i=0;i<4;i++){
        if (!this->materias[i]){
            this->materias[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx){
    if (this->materias[idx])
    {
        this->materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (this->materias[idx])
        this->materias[idx]->use(target);
}

