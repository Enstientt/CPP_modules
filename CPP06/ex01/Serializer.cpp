/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:36:48 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/07 18:49:44 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


uintptr_t  Serialization::serialize(Data *ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serialization::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}