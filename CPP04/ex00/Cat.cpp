/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:52:26 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/29 22:46:51 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
    std::cout<< "Cat default constructor called"<<std::endl;
    this->setType("Cat");
}

Cat::Cat(Cat &copy){
    std::cout << "Cat copy constructor called"<<std::endl;
    *this = copy;
}

Cat::~Cat(){
        std::cout<< "Cat default destructor called"<<std::endl;
}

Cat & Cat::operator=(Cat &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout<<this->getType()<< " 🐈: MEOWING!!!!!! "<<std::endl;
}

