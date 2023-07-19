/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:37:00 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/19 15:35:09 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"


int main()
{
    C a;
    Base *ptr = a.generate();
    C &ref = a;
    ptr->identify(ptr);
    ptr->identify(ref);
    delete ptr;
}