/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:41:32 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/22 12:30:23 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <array>
#include <iostream>
template <typename T>

void iter(T *array, int len, void (*f)( T const &elem)){
    for (int i =0 ;i < len; i++)
        f(array[i]);
};

#endif