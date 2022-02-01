/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:53:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 00:09:03 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Creates " << this->getType() << std::endl;
}

WrongCat::WrongCat(WrongCat const &instance)
{
	*this = instance;
}

WrongCat& WrongCat::operator=(WrongCat const &instance) 
{
	this->name = instance.getType();
	return (*this);
}

WrongCat::~WrongCat() 
{
	std::cout << "Destroy " << this->getType() << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "><><><><><><><" << std::endl;
}
