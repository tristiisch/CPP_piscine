/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:16:05 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 20:01:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Materia.hpp"

AMateria::AMateria(std::string name) : name(name)
{
	this->name = name;
}

std::string const & AMateria::getType() const
{
	return (this->name);
}
