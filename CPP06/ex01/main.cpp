/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:36:46 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/19 15:31:40 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <typeinfo>
int main()
{
    uintptr_t ptr = 4646546;

    Data *data = Serialization::deserialize(ptr);
    std::cout<<"*" <<typeid(data).name()<<std::endl;

    Data *raw = NULL;

     uintptr_t pt = Serialization::serialize(raw);
     uintptr_t ptt = Serialization::serialize(raw);
    std::cout<<"**" <<typeid(pt).name()<<std::endl;
    std::cout<<"***" <<typeid(ptt).name()<<std::endl;
    std::cout<<typei
    
}