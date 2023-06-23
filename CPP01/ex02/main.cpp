/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:39:16 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/18 00:44:09 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *str_ptr = &str;
    std::string &str_ref = str;
    std::cout << "str: " << &str << std::endl;
    std::cout << "str_ptr: " << str_ptr << std::endl;
    std::cout << "str_ref: " << &str_ref << std::endl; 
    std::cout << "str: " << str << std::endl;
    std::cout << "str_ptr: " << *str_ptr << std::endl;
    std::cout << "str_ref: " << str_ref << std::endl; 
    return 0;
}