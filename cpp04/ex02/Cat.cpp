/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/02/01 16:07:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "Creates " << this->getType() << std::endl;
}

Cat::Cat(Cat const &instance)
{
	*this = instance;
}

Cat& Cat::operator=(Cat const &instance) 
{
	this->name = instance.getType();
	return (*this);
}

Cat::~Cat() 
{
	delete this->brain;
	std::cout << "Destroy " << this->getType() << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou !" << std::endl;
}
