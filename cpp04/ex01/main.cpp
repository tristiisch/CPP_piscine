/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:50:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 01:43:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// const Animal* dog = new Dog();
	// const Animal* cat = new Cat();

	// std::cout << std::endl;

	// std::cout << dog->getType() << " " << std::endl;
	// std::cout << cat->getType() << " " << std::endl;

	// std::cout << std::endl;

	// cat->makeSound();
	// dog->makeSound();

	// delete dog;
	// delete cat;
	// return 0;
	int size = 10;
	Animal *animals[size];

	for (int i = 0; i < size / 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = size / 2; i < size; ++i)
	{
		animals[i] = new Cat();
	}


	for (int i = 0; i < size; ++i)
	{
		delete animals[i];
	}
}
