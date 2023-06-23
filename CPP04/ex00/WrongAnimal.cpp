/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:56:38 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/30 12:58:08 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout<< "WrongAnimal default constructor called"<<std::endl;   
}

WrongAnimal::WrongAnimal(WrongAnimal &copy){
    *this = copy;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}
WrongAnimal::~WrongAnimal(){
    std::cout<< "WrongAnimal distructor called"<<std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
}

void WrongAnimal::makeSound() const{
    std::cout<<"WrongAnimal:Animal sound"<<std::endl;
}