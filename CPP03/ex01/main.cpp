/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:07:58 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:22:22 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // ClapTrap ziko("ziko");
    // std::cout<<"energy for "<< ziko.getName()<< " is "<< ziko.getEnergy()<<std::endl;
    // ziko.setAttackDamage(20);
    // ClapTrap  zaki("zaki");
    // zaki.setAttackDamage(2);
    // std::cout<<"energy for "<< zaki.getName()<< " is "<< zaki.getEnergy()<<std::endl;
    // ziko.attack( "zaki");
    // zaki.takeDamage(ziko.getAttackDamage());
    // std::cout<<"energy for "<< ziko.getName()<< " is "<< ziko.getEnergy()<<std::endl;
    // std::cout<<"hit points for "<< zaki.getName()<< " is "<< zaki.getHitPoint()<<std::endl;
    // zaki.attack("zaki");
    ScavTrap zakki;
    ScavTrap zaki("zaki");
    ScavTrap ziko("ziko");
    zaki.attack("ziko");
    ziko.takeDamage(zaki.getAttackDamage());
    std::cout<<ziko.getHitPoint()<<std::endl;
    zaki.guardGate();
    zaki = ziko;
     std::cout<<zaki.getHitPoint()<<std::endl;
}