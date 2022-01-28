/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 16:30:29 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default created." << std::endl;
}

Animal::Animal(std::string name): name(name)
{
	std::cout << "Animal " << name << " created." << std::endl;
}

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
	std::cout << "Animal " << name <<  " destroyed." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Default Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->name);
}
