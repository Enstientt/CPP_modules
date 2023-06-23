/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:04:11 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/19 13:30:55 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2)
{
}

Sed::~Sed()
{
}

void Sed::replace(void)
{
    std::ifstream ifs(_filename);
    std::ofstream ofs(_filename + ".replace");
    std::string line;

    if (!ifs.is_open())
    {
        std::cout << "Error: File not found" << std::endl;
        return;
    }
    if (!ofs.is_open())
    {
        std::cout << "Error : creation of the file failed" << std::endl;
        return;
    }
    if (_s1 != "") {
        while (std::getline(ifs, line)) {
            size_t pos = 0;
            while ((pos = line.find(_s1, pos)) != std::string::npos) {
                line = line.substr(0, pos) + _s2 + line.substr(pos + _s1.length());
                pos += _s2.length();
            }
            ofs << line <<std::endl ;
        }
    }

    ifs.close();
    ofs.close();
}
