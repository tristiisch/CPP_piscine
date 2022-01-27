/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 22:27:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int DiamondTrap::hitPointsDefault = 100;
int DiamondTrap::energyPointsDefault = 100;
int DiamondTrap::attackDamageDefault = 30;

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = ClapTrap::getName();
	ClapTrap::name = this->getName() + "_clap_name";
	std::cout << "Create DiamondTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = FragTrap::hitPointsDefault;
	this->energyPoints = ScavTrap::energyPointsDefault;
	this->attackDamage = FragTrap::attackDamageDefault;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "Create DiamondTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = FragTrap::hitPointsDefault;
	this->energyPoints = ScavTrap::energyPointsDefault;
	this->attackDamage = FragTrap::attackDamageDefault;
	ClapTrap::name = this->getName() + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap const &instance) : ScavTrap(instance)
{
	std::cout << "Create cloned DiamondTrap '" << this->getName() << "'." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &instance)
{
	this->name = instance.getName();
	this->hitPoints = instance.getHitPoints();
	this->energyPoints = instance.getEnergyPoints();
	this->attackDamage = instance.getAttackDamage();
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

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName() const
{
	return (this->name);
}
