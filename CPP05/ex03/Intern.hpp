/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:31:56 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/04 17:21:48 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
    private:
        /*code here*/
    public:
        Intern();
        ~Intern();
        Intern(const Intern & copy);
        Intern& operator=( const Intern& rhs );
        AForm*   makeForm( std::string name, std::string target );
};

#endif