/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 19:15:02 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int ScavTrap::hitPointsDefault = 100;
int ScavTrap::energyPointsDefault = 50;
int ScavTrap::attackDamageDefault = 20;

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Create ScavTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = this->hitPointsDefault;
	this->energyPoints = this->energyPointsDefault;
	this->attackDamage = this->attackDamageDefault;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Create ScavTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = this->hitPointsDefault;
	this->energyPoints = this->energyPointsDefault;
	this->attackDamage = this->attackDamageDefault;
}

ScavTrap::ScavTrap(ScavTrap const &instance) : ClapTrap(instance)
{
	std::cout << "Create cloned ScavTrap '" << this->getName() << "'." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &instance)
{
	this->name =instance.getName();
	this->hitPoints = instance.getHitPoints();
	this->energyPoints = instance.getEnergyPoints();
	this->attackDamage = instance.getAttackDamage();
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

void ScavTrap::attack(const std::string &target) 
{
	if (!this->hasEnoughEnergy())
		return;
	--this->energyPoints;
	std::cout << "[ATTACK ScavTrap] " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
