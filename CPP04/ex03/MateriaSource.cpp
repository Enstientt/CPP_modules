/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:19:10 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 00:01:17 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    //std::cout<<"default constructor called"<<std::endl;
     for (size_t i = 0; i < 4; i++)
    {
        this->_materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(std::string type){
    this->_type = type;
    for (size_t i = 0; i < 4; i++)
    {
        this->_materias[i] = NULL;
    }
    
}

MateriaSource::~MateriaSource(){
    //std::cout<<"default distructor called"<<std::endl;
    for (size_t i = 0; i < 4; i++)
    {
       if (this->_materias[i])
            delete this->_materias[i];
    }
    
}
MateriaSource::MateriaSource(MateriaSource &copy){
    *this = copy;
}
MateriaSource& MateriaSource::operator=(MateriaSource &copy){
    if (this!=&copy){
        this->_type = copy._type;
        for(int i = 0;i<4;i++){
            if (this->_materias[i])
                delete this->_materias[i];
            this->_materias[i] = copy._materias[i];
        }
    }
    return *this;
 }

AMateria* MateriaSource::createMateria(std::string const & type){
    for (size_t i = 0; i < 4; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type )
        {
             return this->_materias[i]->clone();
        }
    }
    return (NULL);
}

void MateriaSource::learnMateria(AMateria* materia){
    for (size_t i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = materia;
            return;
        }
    }
}