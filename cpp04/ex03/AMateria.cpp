/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:19:50 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:19:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : name("nameless") {}

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