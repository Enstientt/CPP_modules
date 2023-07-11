/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:36:56 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/10 11:36:57 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>

class Base{
    public:
        virtual ~Base();
        Base *generate(void);
        void identify(Base * p);
        void identify(Base &p);
        
};

class A:public Base{

};
class B:public Base{

};
class C:public Base{

};
#endif