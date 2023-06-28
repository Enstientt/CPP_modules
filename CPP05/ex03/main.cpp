/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/27 17:55:22 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main()   
{
     Bureaucrat mee("mee", 5);
    Intern me;
    AForm   *form;
    
    form = me.makeForm("robotomy request", "bender");
    if (form == NULL)
        return 1;
    mee.signForm(*form);
    mee.executeForm(*form);
    delete form;
    return 0;
}
