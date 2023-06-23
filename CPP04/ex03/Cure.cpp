/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:05:21 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 00:02:33 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(){
    //std::cout<<"Cure default constructor called"<<std::endl;
    this->type = "cure";
}

Cure::~Cure(){
    //std::cout<<"Cure  distructor called"<<std::endl;
}

Cure::Cure(Cure &copy){
     //std::cout<<"Cure copy constructor called"<<std::endl;
     *this = copy; 
}

Cure &Cure::operator=(Cure &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}

AMateria *Cure::clone() const{
    AMateria *ret = new Cure();
    return ret;
}

void Cure::use(ICharacter& target){
    std::cout<<"* heals " + target.getName() + "'s wounds *"<<std::endl;
}