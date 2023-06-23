/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:02:09 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/19 14:20:16 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed
{
    private:
        std::string	_filename;
        std::string	_s1;
        std::string	_s2;
    public:
        Sed(std::string filename, std::string s1, std::string s2);
        ~Sed();
        void	replace(void);
};
 
#endif