/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/06 17:13:43 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try{
    const Bureaucrat burss("nn", 45);
    Bureaucrat burea("line", 140);
    std::cout<< burea<<std::endl;
    burea.incrementGrade();
    std::cout<< burea<<std::endl;
     burea.decrementGrade();
    std::cout<< burea<<std::endl;
    Bureaucrat bure(burea);
    std::cout<<"*******"<<std::endl;
    std::cout<< bure<<std::endl;
    std::cout<<"*******12"<<std::endl;
    std::cout << burss.getName()<<std::endl;
    }
    catch(std::exception & e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}