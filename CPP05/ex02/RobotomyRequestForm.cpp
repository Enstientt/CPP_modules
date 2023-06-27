/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:28 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/27 14:55:10 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    (void)copy;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeE())
        throw AForm::GradeTooLowException();
    std::cout<< "some drilling noises"<<std::endl;
    srand((unsigned) time(NULL));
    int i = rand() % 2;
    if (i)
    {
        std::cout<<this->_target<<" has been robotomized successfully"<<std::endl;
    }
    else
    {
        std::cout<<"It’s a failure"<<std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const 
{
    return (this->_target);
}