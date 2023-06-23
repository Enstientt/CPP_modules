/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:05:28 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/30 20:29:43 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice:public AMateria{
    public:
        Ice();
        Ice(Ice &copy);
        Ice & operator=(Ice &copy);
        virtual ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};
#endif