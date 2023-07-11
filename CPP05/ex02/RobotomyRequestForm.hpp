/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:29 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/09 15:07:46 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

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
        void execute(Bureaucrat const & executor) const;
};
#endif