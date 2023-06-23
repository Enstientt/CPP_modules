/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:51:47 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/19 16:27:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(){
std::cout<<"Form constructor called"<<std::endl;
}

Form::~Form(){
    std::cout<<"Form destructor called"<<std::endl;
}

Form::Form(std::string name,  int gradeE, int gradeS) : _name(name) , _gradeE(gradeE), _gradeS(gradeS)
{
    std::cout<<"Form constructor called"<<std::endl;
    if (gradeS < 1 || gradeE < 1)
        throw GradeTooHighException();
    if (gradeS> 150 || gradeE > 150)
        throw GradeTooLowException();
    this->_gradeS = gradeS;
    this->_gradeE = gradeE;
}


Form & Form::operator=(Form const  &copy){
    if (this != &copy)
    {
        this->_gradeS = copy._gradeS;
        this->_gradeE = copy._gradeE;
        this->_signed = copy._signed;
    }
    return *this;
}

Form::Form(Form const &copy){
    *this = copy;
}

std::string Form::getName(){
    return this->_name;
}

int Form::getGradeS(){
    return this->_gradeS;
}

int Form::getGradeE(){
    return this->_gradeE;
}

bool Form::getSigne(){
    return this->_signed;
}
// void Form::decrementGrade(){
//     if (this->_gradeE > 150)
//         throw "grade out of range (min)"; 
//     this->_grade++;
// }

// void Form::incrementGrade(){
//     if (this->_grade - 1 < 1)
//         throw "grade out of range (max)"; 
//     this->_grade--;
// }

const char* Form::GradeTooLowException::what() const throw()
    {
         return "grade too low ";
    }

const char* Form::GradeTooHighException::what() const throw()
    {
         return "grade too high ";
    }
void Form::beSigned(Bureaucrat bureaucrat)
{
    try
    {
        if (bureaucrat.getGrade() < 1)
            throw GradeTooHighException();
        if (bureaucrat.getGrade() > 150)
            throw GradeTooLowException();
        if (this->getGradeS() >= bureaucrat.getGrade())
        {
            this->_signed = true;
            std::cout<< this->getName()<< " signed  the form "<<std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
std::ostream & operator<<(std::ostream &o,Form &rh )
{
    o<<rh.getName()<<" the Form : "<<std::endl;
    o<<"signed grade "<< rh.getGradeS()<<std::endl;
    o<<"executed grade "<< rh.getGradeE()<<std::endl;
    o<<"signe "<<rh.getSigne()<<std::endl;
    return o;
}