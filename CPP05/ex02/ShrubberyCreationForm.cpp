/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:31 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/25 20:39:58 by zessadqu         ###   ########.fr       */
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
    if (executor.getGrade() > this->getGradeE())
        throw AForm::GradeTooLowException();
    std::ofstream file;
    file.open(this->_target + "_shrubbery");
       file<<"v .   ._, |_  .,                   "<<std::endl;
       file<< "   `-._\/  .  \ /    |/_          "<<std::endl;
       file<< "       \\  _\, y | \//            "<<std::endl;
       file<< " _\_.___\\, \\/ -.\||             "<<std::endl;
       file<< "   `7-,--.`._||  / / ,            "<<std::endl;
       file<< "   /'     `-. `./ / |/_.'         "<<std::endl;
       file<< "             |    |//             "<<std::endl;
       file<< "             |_    /              "<<std::endl;
       file<< "             |-   |               "<<std::endl;
       file<< "             |   =|               "<<std::endl;
       file<< "             |    |               "<<std::endl;
       file<< "----------------/ ,  . \--------._"<<std::endl;
    file.close();
}

std::string ShrubberyCreationForm::getTarget() const 
{
    return (this->_target);
}

