/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:03:41 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/18 20:07:39 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }
    Sed sed(argv[1], argv[2], argv[3]);
    sed.replace();
    return (0);
}