/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 15:43:41 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Create ScavTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name)  : ClapTrap(name)
{
	std::cout << "Create ScavTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &instance)  : ClapTrap(instance)
{
	std::cout << "Create cloned ScavTrap '" << this->getName() << "'." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &instance)
{
	this->setName(instance.getName());
	this->setHitPoints(instance.getHitPoints());
	this->setEnergyPoints(instance.getEnergyPoints());
	this->setAttackDamage(instance.getAttackDamage());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " was destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
	if (!this->hasEnoughEnergy())
		return;
	std::cout << this->getName() << " enter in Gate keeper mode." << std::endl;
}
