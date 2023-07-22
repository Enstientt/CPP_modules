/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:44:59 by zessadqu          #+#    #+#             */
/*   Updated: 2023/07/22 11:54:11 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array{
    private:
        unsigned int _size;
	T *array;

    public:
        Array(){
            this->_size = 0;
            array = new T[_size];
            std::cout << "Array created" << std::endl;
        };
        Array<T>(unsigned int n){
            this->_size = n;
            array = new T[n];
        };
        Array<T>(Array<T> const &copy){
            *this = copy;
        };
        Array<T> &operator=(Array<T> const &copy){
            if (this != &copy)
            {
                this->_size = copy._size;
                this->array = new T[this->_size];
                for (unsigned int i = 0; i < this->_size; i++)
                    this->array[i] = copy.array[i];
            }
            return (*this);
        };
        T &operator[](unsigned int i){
            if (i >= this->_size || i < 0)
                throw std::exception();
            return (this->array[i]);
        };
        unsigned int size() const{
            return (this->_size);
        }; 
	~Array()
	{
		delete[] array;
	}
};                                                                                                                                                                                                                                                           
#endif
