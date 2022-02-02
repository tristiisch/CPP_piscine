/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:54:12 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Creates " << this->getType() << std::endl;
}

Dog::Dog(Dog const &instance)
{
	*this = instance;
}

Dog& Dog::operator=(Dog const &instance) 
{
	this->name = instance.getType();
	this->brain = new Brain(*instance.getBrain());
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

Brain* Dog::getBrain() const
{
	return (this->brain);
}
