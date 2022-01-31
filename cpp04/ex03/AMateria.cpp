/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:16:05 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 13:24:36 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Materia.hpp"

AMateria::AMateria() : name("empty") {}

AMateria::AMateria(AMateria const &instance)
{
	*this = instance;
}

AMateria::AMateria(std::string name) : name(name) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (this->name);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "An error occurred with AMateria::use()." << std::endl;
}