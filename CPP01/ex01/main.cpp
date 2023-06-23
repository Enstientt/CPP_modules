/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:03:39 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/19 13:39:50 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{   
    Zombie* zombie_hord = zombieHorde(5, "zimbabue");
    for (int i = 0; i < 5; i++)
        zombie_hord[i].announce();
    delete [] zombie_hord;
    return (0);
}
