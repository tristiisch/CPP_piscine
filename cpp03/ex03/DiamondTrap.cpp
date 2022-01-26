/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/01/26 18:36:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap()
{
	std::cout << "Create DiamondTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

DiamondTrap::DiamondTrap(std::string name) : name(name)
{
	std::cout << "Create DiamondTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

DiamondTrap::DiamondTrap(DiamondTrap const &instance) : ScavTrap(instance)
{
	
	std::cout << "Create cloned DiamondTrap '" << this->getName() << "'." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &instance)
{
	this->setName(instance.getName());
	this->setHitPoints(instance.getHitPoints());
	this->setEnergyPoints(instance.getEnergyPoints());
	this->setAttackDamage(instance.getAttackDamage());
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->getName() << " was destroyed." << std::endl;
}

void DiamondTrap::guardGate()
{
	if (!this->hasEnoughEnergy())
		return;
	std::cout << this->getName() << " enter in Gate keeper mode." << std::endl;
}
