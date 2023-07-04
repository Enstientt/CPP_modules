/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/04 16:33:10 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()   
{
    try
    {
        Bureaucrat bureaucrat("name1", 52);
        Form form("zaki", 56, 50);
        form.beSigned(bureaucrat);
        std::cout<<"******"<<std::endl;
        bureaucrat.signForm(form);
        // std::cout << form<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

        try
    {
        Bureaucrat bureaucrat("nzz", 52);
        Form form("zai", 56, 60);
        form.beSigned(bureaucrat);
        std::cout<<"******"<<std::endl;
        bureaucrat.signForm(form);
        // std::cout << form<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
