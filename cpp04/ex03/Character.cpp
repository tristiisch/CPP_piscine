/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:02:19 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:20:03 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("nameless")
{
	this->initInventory();
}

Character::Character(std::string name) : name(name)
{
	this->initInventory();
}

Character::Character(Character const &instance)
{
	this->initInventory();
	*this = instance;
}

Character &Character::operator=(Character const & instance)
{
	this->name = instance.getName();
	for (int i = 0; i < MAX_INV; ++i)
	{
		if (instance.inventory[i])
			this->inventory[i] = instance.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	for (int idx = 0; idx < MAX_INV; ++idx)
	{
		if (this->inventory[idx])
		{
			if (DEBUG)
				std::cout << "[DEBUG] Instance of Materia " << this->inventory[idx]->getType() << ", id " << idx << " destroyed in " << this->getName() << "." << std::endl;
			delete this->inventory[idx];
		}
	}
	for (int idx = 0; idx < DELETE_SAFE_BUFFER; ++idx)
	{
		if (this->toDelete[idx])
		{
			if (DEBUG)
				std::cout << "[DEBUG] Instance unEquiped of Materia " << this->toDelete[idx]->getType() << " destroyed in " << this->getName() << "." << std::endl;
			delete this->toDelete[idx];
		}
	}
	if (DEBUG)
		std::cout << "[DEBUG] Character " << this->getName() << " destroyed." << std::endl;
}

void Character::initInventory()
{
	for (int idx = 0; idx < MAX_INV; ++idx)
		this->inventory[idx] = NULL;
	for (int idx = 0; idx < DELETE_SAFE_BUFFER; ++idx)
		this->toDelete[idx] = NULL;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{	
		std::cout << "The materia you want to equip is null." << std::endl;
		return;
	}
	for (int idx = 0; idx < MAX_INV; ++idx)
	{
		if (!this->inventory[idx])
		{
			this->inventory[idx] = m;
			if (DEBUG)
				std::cout << "[DEBUG] Equip materia " << this->inventory[idx]->getType() << " to slot " << idx << "." << std::endl;
			return;
		}
		else if (this->inventory[idx] == m)
		{
			std::cout << "Materia " << this->inventory[idx]->getType() << " is already equip. You need to create an other instance." << std::endl;
			return;
		}
	}
	if (DEBUG)
		std::cout << "[DEBUG] Can't equip material " << m->getType() << ", inventory of " << this->getName() << " is full." << std::endl;
			
}

void Character::unequip(int idx)
{
	if (!this->inventory[idx])
	{
		std::cout << "Materia id " << idx << " is null in inventory of " << this->getName() << std::endl;
		return;
	}
	this->inventory[idx] = NULL;
}


void Character::unEquipSafe(int idx)
{
	AMateria* materia;

	if (!this->inventory[idx])
	{
		std::cout << "Materia id " << idx << " is null in inventory of " << this->getName() << std::endl;
		return;
	}
	materia = this->inventory[idx];
	this->inventory[idx] = NULL;
	for (int i = 0; i < DELETE_SAFE_BUFFER; ++i)
	{
		if (!this->toDelete[i])
		{
			this->toDelete[i] = materia;
			return;
		}
	}
	if (DEBUG)
		std::cout << "[DEBUG] The buffer of unEquipSafe is full. The instance of " << materia->getType() << " is delete right now." << std::endl;
	delete materia;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INV)
	{
		std::cout << "Id " << idx << " of inventory of " << this->getName() << " is not in range of 0 to " << (MAX_INV - 1) << "." << std::endl;
		return;
	}
	if (!this->inventory[idx])
	{
		std::cout << "Materia id " << idx << " is null in inventory of " << this->getName() << std::endl;
		return;
	}
	this->inventory[idx]->use(target);
}
