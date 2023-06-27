/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:00 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/25 21:50:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;
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
        std::string getName() const ;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm  &form);
        Bureaucrat & operator=(Bureaucrat & copy);
        void executeForm(AForm const & form);
};
std::ostream & operator<<(std::ostream &o,Bureaucrat &rh );
#endif