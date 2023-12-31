/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:51:47 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/18 14:02:34 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_name("null"), _signed(false),_gradeS(1),  _gradeE(1) {
}

AForm::~AForm(){
}

AForm::AForm(std::string name,  int gradeE, int gradeS) : _name(name), _gradeS(gradeS), _gradeE(gradeE)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS> 150 || gradeE > 150)
        throw GradeTooLowException();
}

AForm & AForm::operator=(AForm const  &copy)
   {
    if (this != &copy)
    {
        this->_signed = copy._signed;
    }
    return *this;
}

AForm::AForm(AForm const &copy): _name(copy._name), _gradeS(copy._gradeS), _gradeE(copy._gradeE){
    *this = copy;
}

std::string AForm::getName() const{
    return this->_name;
}

int AForm::getGradeS() const{
    return this->_gradeS;
}

int AForm::getGradeE() const{
    return this->_gradeE;
}

bool AForm::getSigne() const {
    return this->_signed;
}

const char* AForm::GradeTooLowException::what() const throw()
    {
         return "grade too low";
    }

const char* AForm::GradeTooHighException::what() const throw()
    {
         return "grade too high";
    }

const char* AForm::NotSignedException::what() const throw()
    {
         return "form not signed.";
    }

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    try
    {
        if (this->getGradeS() >= bureaucrat.getGrade())
            this->_signed = true;
        else
            throw GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<std::endl;
    }
    
}

std::ostream & operator<<(std::ostream &o,AForm &rh )
{
    o<<" The Form : "<<rh.getName()<<std::endl;
    o<<"signed grade "<< rh.getGradeS()<<std::endl;
    o<<"executed grade "<< rh.getGradeE()<<std::endl;
    o<<"signe "<<rh.getSigne()<<std::endl;
    return o;
}
