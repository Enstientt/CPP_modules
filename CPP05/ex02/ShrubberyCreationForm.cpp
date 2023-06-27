/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:31 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/27 17:10:14 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    (void)copy;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::cout<<"the execute ShrubberyCreationForm function is called"<<std::endl;
    if (executor.getGrade() > this->getGradeE())
        throw AForm::GradeTooLowException();
    std::ofstream fil((this->getTarget() + "_shrubbery").c_str());
    
    if (!fil.is_open())
    {
            std::cout<<"Error opening file"<<std::endl;
            return ;
    };
    fil <<"v .   ._, |_  .,                   "<<std::endl;
    fil<< "   `-._/  .   /    |/_          "<<std::endl;
    fil<< "       \\  _, y | /            "<<std::endl;
    fil<< " __.___\\, \\/ -.||             "<<std::endl;
    fil<< "   `7-,--.`._||  / / ,            "<<std::endl;
    fil<< "   /'     `-. `./ / |/_.'         "<<std::endl;
    fil<< "             |    |//             "<<std::endl;
    fil<< "             |_    /              "<<std::endl;
    fil<< "             |-   |               "<<std::endl;
    fil<< "             |   =|               "<<std::endl;
    fil<< "             |    |               "<<std::endl;
    fil<< "----------------/ ,  . --------._"<<std::endl;
    fil.close();
}

std::string ShrubberyCreationForm::getTarget() const 
{
    return (this->_target);
}

