/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:29 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/05 14:18:18 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm();
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm & operator=(RobotomyRequestForm const &copy);
        std::string getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
};
#endif