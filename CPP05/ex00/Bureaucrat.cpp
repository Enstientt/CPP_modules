/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:41:56 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/09 15:13:21 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("null"){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name,  int grade  ) : _name(name) ,_grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const &copy){
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name){
      if (this != &copy)
    {
        this->_grade = copy._grade;
    }
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
    {
         return "grade too low";
    }

const char* Bureaucrat::GradeTooHighException::what() const throw()
    {
         return "grade too high";
    }
void Bureaucrat::decrementGrade(){
    if (this->_grade + 1 > 150)
        throw GradeTooLowException() ; 
    this->_grade++;
}

void Bureaucrat::incrementGrade(){
    if (this->_grade - 1 < 1)
        throw GradeTooHighException(); 
    this->_grade--;
}

std::ostream & operator<<(std::ostream &o,Bureaucrat &rh ){
    o << rh.getName() << ", bureaucrat grade "<< rh.getGrade()<<std::endl;
    return o;
}