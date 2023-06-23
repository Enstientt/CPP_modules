/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:52:33 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 11:57:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog:public Animal{
    public:
        Dog();
        Dog(Dog &copy);
        Dog & operator=(Dog &copy);
        virtual ~Dog();
        virtual void makeSound() const;
};
#endif