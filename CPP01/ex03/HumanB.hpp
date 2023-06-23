/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:48:21 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/18 18:36:34 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string	_name;
        Weapon		*_weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void	attack(void);
        void	setWeapon(Weapon &weapon);
};

#endif