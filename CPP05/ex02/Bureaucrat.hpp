/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:00 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/18 11:23:19 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat{
     class TooLowGrade: public std::exception
    {
    	public:
    	    virtual const char* what() const throw();
    };
        class TooHighGrade: public std::exception
    {
    	public:
    	    virtual const char* what() const throw();
    };
    private:
        std::string _name;
        int _grade;
    public :
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat(std::string name, int grade);
        std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();
        void signForm(Form form);
        Bureaucrat & operator=(Bureaucrat & copy);
};
std::ostream & operator<<(std::ostream &o,Bureaucrat &rh );
#endif