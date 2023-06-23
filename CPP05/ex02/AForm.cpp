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

AForm::AForm(){
std::cout<<"AForm constructor called"<<std::endl;
}

AForm::~AForm(){
    std::cout<<"AForm destructor called"<<std::endl;
}

AForm::AForm(std::string name,  int gradeE, int gradeS) : _name(name)
{
    std::cout<<"AForm constructor called"<<std::endl;
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS> 150 || gradeE > 150)
        throw GradeTooLowException();
    this->_gradeS = gradeS;
    this->_gradeE = gradeE;
}


AForm & AForm::operator=(AForm const  &copy){
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_gradeS = copy._gradeS;
        this->_gradeE = copy._gradeE;
        this->_signed = copy._signed;
    }
    return *this;
}

AForm::AForm(AForm const &copy){
    *this = copy;
}

std::string AForm::getName(){
    return this->_name;
}

int AForm::getGradeS(){
    return this->_gradeS;
}

int AForm::getGradeE(){
    return this->_gradeE;
}

bool AForm::getSigne(){
    return this->_signed;
}
// void AForm::decrementGrade(){
//     if (this->_gradeE > 150)
//         throw "grade out of range (min)"; 
//     this->_grade++;
// }

// void AForm::incrementGrade(){
//     if (this->_grade - 1 < 1)
//         throw "grade out of range (max)"; 
//     this->_grade--;
// }

const char* AForm::GradeTooLowException::what() const throw()
    {
         return "grade too low ";
    }

const char* AForm::GradeTooHighException::what() const throw()
    {
         return "grade too high ";
    }
void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() < 1 )
     return;
}
std::ostream & operator<<(std::ostream &o,AForm &rh )
{
    o<<rh.getName()<<"AForm has : "<<std::endl;
    o<<"signed grade "<< rh.getGradeS()<<std::endl;
    o<<"executed grade "<< rh.getGradeE()<<std::endl;
    o<<"signe"<<rh.getSigne()<<std::endl;
    return o;
}