/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:52:31 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/29 22:47:04 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
    std::cout<< "Dog default constructor called"<<std::endl;
    this->setType("Dog");
}

Dog::Dog(Dog &copy){
    std::cout << "Dog copy constructor called"<<std::endl;
    *this = copy;
}

Dog::~Dog(){
        std::cout<< "Dog default destructor called"<<std::endl;
}

Dog & Dog::operator=(Dog &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}

void Dog::makeSound() const{
    std::cout<<this->getType()<< " 🐕: BARKING!!!!!! "<<std::endl;
}