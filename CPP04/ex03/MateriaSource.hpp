/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:19:13 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/01 20:15:33 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource:public IMateriaSource{
    private:
        std::string _type;
        AMateria *_materias[4];
    public:
        MateriaSource();
        MateriaSource(std::string type);
        MateriaSource(MateriaSource &copy);
        MateriaSource & operator=(MateriaSource &copy);
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
        
};
#endif