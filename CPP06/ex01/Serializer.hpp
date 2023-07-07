/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:36:50 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/07 18:48:50 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
#include <iostream>
struct Data{
    int n;
    std::string name;
};

class Serialization{
    private:
        Serialization();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
};
#endif