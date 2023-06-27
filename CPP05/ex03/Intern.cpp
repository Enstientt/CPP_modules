/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:31:53 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/27 14:50:51 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
    
}

Intern::~Intern(){}

Intern::Intern(const Intern & copy ) 
{
    (void)copy;
    *this = copy;
}

Intern& Intern::operator=( const Intern& rhs ) {
    ( void ) rhs;
    return (*this);
}

AForm * Intern::makeForm(std::string name, std::string target )
{
    std::string formName[] = {"robotomy request", "presidential pardon","shrubbery creation"};

    AForm * formFun[] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
    for (int i = 0; i< 3;i++)
    {
        if (name == formName[i])
        {
            std::cout<< "Intern creates"<< name<<std::endl;
            return formFun[i];
        }
    }
    std::cout << "Intern couldn't creat "<< name <<std::endl;
    return NULL;
}