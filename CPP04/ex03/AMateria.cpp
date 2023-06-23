/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:58:14 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 14:28:12 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
    //std::cout<<"AMateria default constructor called"<<std::endl;
    this->type = "default";
}

AMateria::AMateria(std::string const & type){
   //std::cout<<"AMateria constructor called"<<std::endl;
    this->type=type;
}

AMateria::AMateria(AMateria &copy){
    *this = copy;
}

AMateria::~AMateria(){
    // std::cout<<"AMateria disconstructor called"<<std::endl;
}

std::string const & AMateria::getType() const{
    return this->type;
}

AMateria & AMateria:: operator=(AMateria &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}

 void AMateria::use(ICharacter& target){
    (void)target;
 }