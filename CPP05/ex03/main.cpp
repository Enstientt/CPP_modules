/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/10 16:37:15 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()   
{
    Bureaucrat mee("mee", 30);
    Intern me;
    AForm   *form;
    
    form = me.makeForm("robotomy request", "Bender");
    if (form == NULL)                     
        return 1;
    form->beSigned(mee);
    mee.executeForm(*form);
    delete form;  
    return 0;
}
