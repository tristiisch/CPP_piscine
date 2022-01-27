/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 16:04:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Create DiamondTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	this->setName(ClapTrap::getName());
	ClapTrap::setName(this->getName() + "_clap_name");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "Create DiamondTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
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

void DiamondTrap::whoAmI()
{
	std::cout	<< "My friends known me as DiamondTrap " << this->getName()
				<< " but you can call me ClapTrap " << ClapTrap::getName() << "." << std::endl;
}

std::string DiamondTrap::getName() const
{
	return (this->name);
}

void DiamondTrap::setName(std::string name) 
{
	this->name = name;
}
