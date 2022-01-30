/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:02:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 20:09:47 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Materia.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(Cure const &instance) : AMateria("cure")
{
	*this = instance;
}

Cure::~Cure()
{

}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wound *" << std::endl; 
}
