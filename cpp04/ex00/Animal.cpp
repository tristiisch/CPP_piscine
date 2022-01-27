/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 00:10:46 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(std::string name): name(name) {}

Animal::Animal(Animal const &instance)
{
	*this = instance;
}

Animal& Animal::operator=(Animal const &instance) 
{
	this->name = instance.getType();
	return (*this);
}

Animal::~Animal() 
{
	
}

void Animal::makeSound() const
{
	std::cout << "Default Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->name);
}
