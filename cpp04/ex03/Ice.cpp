/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:02:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 20:09:38 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Materia.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(Ice const &instance) : AMateria("ice")
{
	*this = instance;
}

Ice::~Ice()
{

}

Ice* Ice::clone() const
{
	return new Ice(*this);
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}
