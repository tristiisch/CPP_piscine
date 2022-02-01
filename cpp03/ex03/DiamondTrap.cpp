/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/02/01 16:07:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int DiamondTrap::hitPointsDefault = FragTrap::hitPointsDefault;
int DiamondTrap::energyPointsDefault = ScavTrap::energyPointsDefault;
int DiamondTrap::attackDamageDefault = FragTrap::attackDamageDefault;

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = ClapTrap::getName();
	ClapTrap::name = this->getName() + "_clap_name";
	std::cout << "Creates DiamondTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = this->hitPointsDefault;
	this->energyPoints = this->energyPointsDefault;
	this->attackDamage = this->attackDamageDefault;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "Creates DiamondTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = FragTrap::hitPointsDefault;
	this->energyPoints = ScavTrap::energyPointsDefault;
	this->attackDamage = FragTrap::attackDamageDefault;
}

DiamondTrap::DiamondTrap(DiamondTrap const &instance) : ScavTrap(instance)
{
	std::cout << "Creates cloned DiamondTrap '" << this->getName() << "'." << std::endl;
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
