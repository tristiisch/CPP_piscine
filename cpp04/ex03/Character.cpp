/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:02:19 by tglory            #+#    #+#             */
/*   Updated: 2022/01/30 19:53:20 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character() : ICharacter("nameless")
{
	this->initInventory();
}

Character::Character(std::string name) : ICharacter(name)
{
	this->initInventory();
}

Character::Character(Character const &instance)
{
	this->initInventory();
	*this = instance;
}

Character::~Character()
{

}

void Character::initInventory()
{
	for(int i = 0; i < MAX_INV; i++)
		this->inventory[i] = NULL;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int idx = 0; idx < MAX_INV; ++idx)
	{
		if (!this->inventory[idx])
			this->inventory[idx] = m;
	}
}

void Character::unequip(int idx)
{
	if (!this->inventory[idx])
		return;
	this->inventory[idx] = NULL;
	// this->materia = NULL;
}
void Character::use(int idx, ICharacter& target)
{
	if (!this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}
