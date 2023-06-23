/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:51:51 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/18 20:13:27 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP
# include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
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
    private:
        const std::string _name;
        bool _signed;
        int _gradeS;
        int _gradeE;
    public:
        Form();
        ~Form();
        Form(Form const &copy);
        Form(std::string name, int gradeE, int gradeS);
        Form & operator=(Form const &copy);
        std::string getName();
        int getGradeS();
        int getGradeE();
        bool getSigne();
        void  beSigned(Bureaucrat bureaucrate);
};
std::ostream & operator<<(std::ostream &o,Form &rh );
#endif