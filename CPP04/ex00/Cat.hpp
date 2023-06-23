/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:52:29 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 11:57:11 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat:public Animal{
    public:
        Cat();
        Cat(Cat &copy);
        Cat & operator=(Cat &copy);
        virtual ~Cat();
        virtual void makeSound() const;
};
#endif