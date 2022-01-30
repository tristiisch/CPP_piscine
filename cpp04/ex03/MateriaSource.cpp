/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:53:40 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 19:54:57 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Materia.hpp"
# include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}
MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria* materia)
{
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *materia = new Ice();

	return (materia);
}
