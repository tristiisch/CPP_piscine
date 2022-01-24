/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:16:29 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 15:49:06 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : type(type) {}

std::string const &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}
