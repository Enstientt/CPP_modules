/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:28 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/28 17:12:29 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    private:
        /*nothing here*/
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap &copy);
        FragTrap & operator=(FragTrap &copy);
        ~FragTrap(void);
        void highFivesGuys(void);
};
#endif