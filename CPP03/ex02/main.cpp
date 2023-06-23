/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:07:58 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:18:17 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap zakk;
    FragTrap zaki("zaki");
    FragTrap ziko("ziko");
    zaki.attack(ziko.getName());
    ziko.takeDamage(zaki.getAttackDamage());
    ziko.beRepaired(3);
    std::cout<< ziko.getName()<<" energy points are "<<ziko.getEnergy()<< " and hitPoints are "<<ziko.getHitPoint()<<std::endl;
    zaki.highFivesGuys();
    ziko.highFivesGuys();
}