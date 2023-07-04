/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:20 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/03 15:48:15 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
{ 
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):AForm(copy), _target(copy._target)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    (void)copy;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
     if ( executor.getGrade() > this->getGradeE() )
        throw AForm::GradeTooLowException();
    else {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

std::string PresidentialPardonForm::getTarget() const 
{
    return (this->_target);
}