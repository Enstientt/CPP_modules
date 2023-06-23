/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:52:36 by zessadqu          #+#    #+#             */
/*   Updated: 2023/05/02 14:27:12 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int count = 10;


int main( void )
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	delete dog;
	delete cat;
	
	
	const Animal	*(animal_array[count]);
	std::cout << std::endl;
	for (int j = 0; j < count/2; j++)
		animal_array[j] = new Dog();
	std::cout << std::endl;

	for (int j = count/2; j < count; j++)
		animal_array[j] = new Cat();
    for (int j = 0; j < count; j++)
    {
        animal_array[j]->makeSound();
    }
    
	std::cout << std::endl;

	for (int j = 0; j < count; j++)
		delete animal_array[j];
	std::cout << std::endl;
	std::cout << "Deeep copy test"<<std::endl;
	Dog basic;

	{
		Dog tmp = basic;
	}
	return 0;
}