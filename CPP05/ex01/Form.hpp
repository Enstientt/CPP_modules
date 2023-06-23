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
    private:
        const std::string _name;
        const int _gradeS;
        const int _gradeE;
        bool _signed;
        Form();
    public:
        ~Form();
        Form(const Form &copy);
        Form(std::string name, int gradeE, int gradeS);
        Form & operator=(Form const &copy);
        std::string getName();
        int getGradeS();
        int getGradeE();
        bool getSigne();
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
};
std::ostream & operator<<(std::ostream &o,Form &rh );
#endif