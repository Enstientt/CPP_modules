/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:05:23 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/30 20:25:46 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure:public AMateria{
    public:
        Cure();
        Cure(Cure &copy);
        Cure & operator=(Cure &copy);
        virtual ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};
#endif