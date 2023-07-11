/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/10 17:07:08 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()   
{
    AForm *name = new ShrubberyCreationForm("me");
    Bureaucrat bear("zaki", 46);
    std::cout<<name->getGradeE()<<std::endl;
    std::cout<<name->getGradeS()<<std::endl;
    name->beSigned(bear);
    try
    {
        Bureaucrat bureaucrate("namee", 50);
        ShrubberyCreationForm form("garden");
        RobotomyRequestForm robo("tea");
        PresidentialPardonForm rr("tea101");
        form.beSigned(bureaucrate);
        robo.beSigned(bureaucrate);
        rr.beSigned(bureaucrate);
        bureaucrate.signForm(form);
        form.execute(bureaucrate);
        robo.execute(bureaucrate);
        rr.execute(bureaucrate);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }
    delete name;
}
