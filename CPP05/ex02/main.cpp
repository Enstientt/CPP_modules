/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:42:03 by zessadqu          #+#    #+#             */
/*   Updated: 2023/06/27 17:05:09 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()   
{
        try
    {
        Bureaucrat bureaucrate("namee", 4);
        ShrubberyCreationForm form("garden");

        bureaucrate.signForm(form);
        form.execute(bureaucrate);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
