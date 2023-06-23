/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:04:13 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/30 13:04:45 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal{
    public:
        WrongCat();
        WrongCat(WrongCat &copy);
        WrongCat & operator=(WrongCat &copy);
        ~WrongCat();
        void makeSound() const;
};
#endif