/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 01:04:37 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Create " << this->getType() << std::endl;
}

Dog::Dog(Dog const &instance)
{
	*this = instance;
}

Dog& Dog::operator=(Dog const &instance) 
{
	this->name = instance.getType();
	return (*this);
}

Dog::~Dog() 
{
	delete this->brain;
	std::cout << "Destroy " << this->getType() << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woaf woaf !" << std::endl;
}
