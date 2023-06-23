/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:57:27 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/18 00:01:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
    Zombie	*new_zombie = newZombie("Zombie");
    new_zombie->announce();
    delete new_zombie;
    randomChump("rundom");
    return (0);
}