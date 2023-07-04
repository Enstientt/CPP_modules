/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:00 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/03 20:12:32 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;
class Bureaucrat{
     private:
        const std::string _name;
        int _grade;
    public :
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat(std::string name, int grade);
        std::string getName() const ;
        int getGrade() const ;
        void incrementGrade();
        void decrementGrade();
        Bureaucrat & operator=(Bureaucrat & copy);
        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        void signForm(AForm  &form);
        void executeForm(AForm const & form);
};
std::ostream & operator<<(std::ostream &o,Bureaucrat &rh );
#endif