/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/26 23:18:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main()   
{
     Bureaucrat mehdi("mehdi", 5);
    Intern karim;
    AForm   *rrf;
    
    rrf = karim.makeForm("robotomy request", "home");
    if (rrf == NULL)
        return 1;
    mehdi.signForm(*rrf);
    mehdi.executeForm(*rrf);
    delete rrf;
    return 0;
}
