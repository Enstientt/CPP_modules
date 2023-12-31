/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:33 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/05 14:18:35 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const &copy);
        std::string getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
};
#endif