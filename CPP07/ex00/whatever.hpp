/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:36:26 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/13 09:39:55 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
template <typename T>
T max(T x1, T x2){
    return (x1 > x2) ? x1:x2;
};

template <typename T>
T min(T x1, T x2){
    return (x1 > x2) ? x2:x1;
};

template <typename T>

void swap(T &x1, T &x2)
{
    T tmp;

    tmp = x1;
    x1 = x2 ; 
    x2 = tmp;    
};
#endif