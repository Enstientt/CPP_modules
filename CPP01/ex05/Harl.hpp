/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:42:49 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/19 14:26:50 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
    private:
        std::string	_level;
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
    public:
        Harl(std::string level);
        void complain(std::string level);
        ~Harl(void);
};

#endif