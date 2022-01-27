/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 00:17:24 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(std::string name): name(name) {}

WrongAnimal::WrongAnimal(WrongAnimal const &instance)
{
	*this = instance;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &instance) 
{
	this->name = instance.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal() 
{
	
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->name);
}
