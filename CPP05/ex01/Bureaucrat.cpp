/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:41:56 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/19 15:48:32 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
std::cout<<"Bureaucrat constructor called"<<std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout<<"Bureaucrat destructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name,  int grade  ) : _name(name)
{
    std::cout<<"Bureaucrat constructor called"<<std::endl;
    this->_grade = grade;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat & copy){
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy){
      if (this != &copy)
    {
        this->_name = copy._name;
        this->_grade = copy._grade;
    }
}

std::string Bureaucrat::getName(){
    return this->_name;
}

int Bureaucrat::getGrade(){
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

const char* Bureaucrat::TooLowGrade::what() const throw()
    {
         return "grade too low ";
    }

const char* Bureaucrat::TooHighGrade::what() const throw()
    {
         return "grade too high ";
    }
void Bureaucrat::signForm(Form form)
{
    if (form.getSigne() == true)
    {
        std::cout<< this<< "signed"<< form;
    }
    else{
        std::cout<< *this<< " couldn’t sign"<< form << "because of you : you re the rason"<<std::endl;
    }
}
std::ostream & operator<<(std::ostream &o,Bureaucrat &rh ){
    o << rh.getName() << ", bureaucrat grade "<< rh.getGrade()<<std::endl;
    return o;
}