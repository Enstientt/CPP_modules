/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:22:47 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:09:37 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    private:
        /*nothing here*/
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &copy);
        ScavTrap & operator=(ScavTrap &copy);
        ~ScavTrap(void);
        void guardGate();
};
#endif