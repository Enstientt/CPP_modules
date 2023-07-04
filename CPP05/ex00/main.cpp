/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/04 11:57:50 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try{
        
    Bureaucrat burea("line", 140);
    std::cout<< burea<<std::endl;
    burea.incrementGrade();
    std::cout<< burea<<std::endl;
     burea.decrementGrade();
    std::cout<< burea<<std::endl;
    Bureaucrat bure(burea);
    std::cout<<"*******"<<std::endl;
    std::cout<< bure<<std::endl;
    }
    catch(std::exception & e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}