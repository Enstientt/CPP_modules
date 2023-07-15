/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:20 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/15 14:56:34 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5) , _target("Null")
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
        throw GradeTooLowException();
     else if (this->getSigne() == false)
        throw NotSignedException();
    else {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

std::string PresidentialPardonForm::getTarget() const 
{
    return (this->_target);
}