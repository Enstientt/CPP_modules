/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:05:26 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 00:00:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(){
    //std::cout<<"Ice default constructor called"<<std::endl;
    this->type = "ice";
}

Ice::~Ice(){
    //std::cout<<"Ice  distructor called"<<std::endl;
}

Ice::Ice(Ice &copy){
     //std::cout<<"Ice copy constructor called"<<std::endl;
     *this = copy; 
}

Ice &Ice::operator=(Ice &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}

AMateria *Ice::clone() const{
    AMateria *ret = new Ice();
    return ret;
}

void Ice::use(ICharacter& target){
    std::cout<<"* shoots an ice bolt at " + target.getName() + " *" <<std::endl;
}