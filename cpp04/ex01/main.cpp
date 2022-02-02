/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:50:10 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:55:26 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	int size = 10;
	Animal *animals[size];	
	Dog test;

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
