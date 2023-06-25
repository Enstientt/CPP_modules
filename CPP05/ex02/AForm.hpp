/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:51:51 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/18 20:31:22 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
# include "Bureaucrat.hpp" 
class Bureaucrat;
class AForm{
    private:
        std::string _name;
        bool _signed;
        int _gradeS;
        int _gradeE;
    public:
        AForm();
        virtual ~AForm();
        AForm(AForm const &copy);
        AForm(std::string name, int gradeE, int gradeS);
        AForm & operator=(AForm const &copy);
        std::string getName() const;
        virtual void execute(Bureaucrat const & executor) const=0;
        int getGradeS() const;
        int getGradeE() const;
        bool getSigne() const;
        void  beSigned(Bureaucrat bureaucrate);
        class GradeTooLowException: public std::exception
        {
            public:
        	    virtual const char* what() const throw();
        };
        class GradeTooHighException: public std::exception
        {
            public:
        	    virtual const char* what() const throw();
        };
        class NotSignedException: public std::exception
        {
            public:
        	    virtual const char* what() const throw();
        };
        
};
std::ostream & operator<<(std::ostream &o,AForm &rh );
#endif