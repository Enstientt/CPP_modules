/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:41:56 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/25 19:26:52 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
std::cout<<"Bureaucrat constructor called"<<std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout<<"Bureaucrat destructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name,  int grade  ) : _name(name) ,_grade(grade)
{
    std::cout<<"Bureaucrat constructor called"<<std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat & copy){
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy){
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

void Bureaucrat::decrementGrade(){
    if (this->_grade > 150)
        throw "grade out of range (min)"; 
    this->_grade++;
}

void Bureaucrat::incrementGrade(){
    if (this->_grade - 1 < 1)
        throw "grade out of range (max)"; 
    this->_grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
    {
         return "grade too low";
    }

const char* Bureaucrat::GradeTooHighException::what() const throw()
    {
         return "grade too high";
    }
std::ostream & operator<<(std::ostream &o,Bureaucrat &rh ){
    o << rh.getName() << ", bureaucrat grade "<< rh.getGrade()<<std::endl;
    return o;
}