/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:43:46 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/15 15:06:08 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    (void)ac;
    if(av[1])
    {
        try
        {
            /* code */
            ScalarConverter::convert(av[1]);
        }
        catch(const std::exception& e)
        {
        }
        
    }
    return 0;
}