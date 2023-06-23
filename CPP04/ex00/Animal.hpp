/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:52:23 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/29 22:46:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(Animal &copy);
        virtual ~Animal();
        Animal & operator=(Animal &copy);
        void setType(std::string);
        std::string getType() const;
        virtual void makeSound() const ;
};
#endif
