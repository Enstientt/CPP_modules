/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:51:47 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/10 11:02:29 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("null") , _gradeE(1), _gradeS(1), _signed(false)
{
}

Form::~Form(){
}

Form::Form(std::string name,  int gradeE, int gradeS) : _name(name) , _gradeE(gradeE), _gradeS(gradeS), _signed(false)
{
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS> 150 || gradeE > 150)
        throw GradeTooLowException();
}


Form & Form::operator=(Form const  &copy){
    if (this != &copy)
        this->_signed = copy._signed;
    return *this;
}

Form::Form(const Form &copy) : _gradeE(copy._gradeE), _gradeS(copy._gradeS), _signed(copy._signed){
    *this = copy;
}

std::string Form::getName() const{
    return this->_name;
}

int Form::getGradeS() const
{
    return this->_gradeS;
}

int Form::getGradeE() const
{
    return this->_gradeE;
}

bool Form::getSigne() const
{
    return this->_signed;
}

const char* Form::GradeTooLowException::what() const throw()
    {
         return "Form:grade too low";
    }

const char* Form::GradeTooHighException::what() const throw()
    {
         return "Form:grade too high";
    }
void Form::beSigned(Bureaucrat &bureaucrat)
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
        std::cout << e.what() <<std::endl;
    }
    
}
std::ostream & operator<<(std::ostream &o,Form &rh )
{
    o<<" the Form : "<<rh.getName()<<std::endl;
    o<<"signed grade "<< rh.getGradeS()<<std::endl;
    o<<"executed grade "<< rh.getGradeE()<<std::endl;
    o<<"signe "<<rh.getSigne()<<std::endl;
    return o;
}