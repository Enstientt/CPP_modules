/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:26 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/09 15:07:42 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define  PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm: public AForm{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm & operator=(PresidentialPardonForm const &copy);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};
#endif