/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:02:31 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/29 22:46:38 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    std::cout<< "Animal default constructor called"<<std::endl;   
}

Animal::Animal(Animal &copy){
    *this = copy;
}

Animal & Animal::operator=(Animal &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}
Animal::~Animal(){
    std::cout<< "Animal distructor called"<<std::endl;
}

std::string Animal::getType() const{
    return this->type;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

void Animal::makeSound() const{
    std::cout<<"parent implementation"<<std::endl;
}