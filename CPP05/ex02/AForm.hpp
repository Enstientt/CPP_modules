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
# include "Bureaucrat.hpp" 
class Bureaucrat;
class AForm{
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
        std::string _name;
        bool _signed;
        int _gradeS;
        int _gradeE;
    public:
        AForm();
        ~AForm();
        AForm(AForm const &copy);
        AForm(std::string name, int gradeE, int gradeS);
        AForm & operator=(AForm const &copy);
        std::string getName();
        int getGradeS();
        int getGradeE();
        bool getSigne();
        void  beSigned(Bureaucrat bureaucrate);
        
};
std::ostream & operator<<(std::ostream &o,AForm &rh );
#endif