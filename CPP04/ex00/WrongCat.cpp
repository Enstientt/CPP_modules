/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:04:19 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/30 13:05:37 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout<< "WrongCat default constructor called"<<std::endl;
    this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat &copy){
    std::cout << "WrongCat copy constructor called"<<std::endl;
    *this = copy;
}

WrongCat::~WrongCat(){
        std::cout<< "WrongCat default destructor called"<<std::endl;
}

WrongCat & WrongCat::operator=(WrongCat &copy){
    if (this !=&copy)
        this->type = copy.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout<<this->getType()<< " 🐈: MEOWING!!!!!! "<<std::endl;
}
