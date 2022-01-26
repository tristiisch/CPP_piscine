/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:18:34 by tglory            #+#    #+#             */
/*   Updated: 2022/01/26 14:19:11 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("nameless"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Create ClapTrap '" << this->name << "'." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Create ClapTrap '" << this->name << "'." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &instance)
{
	*this = instance;
	std::cout << "Create cloned ClapTrap '" << this->name << "'." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &instance)
{
	this->name = instance.getName();
	this->hitPoints = instance.getHitPoints();
	this->energyPoints = instance.getEnergyPoints();
	this->attackDamage = instance.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " was destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) 
{
	if (!this->hasEnoughEnergy())
		return;
	--this->energyPoints;
	std::cout << "[ATTACK] " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
	if (this->hitPoints == 0)
	{
		std::cout << "[HITTED] " << this->name << " is already dead. Unable to attack a corpse." << std::endl;
	}
	else if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "[HITTED] " << this->name << " loose " << amount << " hit points. He die." << std::endl;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "[HITTED] " << this->name << " loose " << amount << " hit points. He had now " << this->hitPoints << " hit point." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) 
{
	if (!this->hasEnoughEnergy())
		return;
	--this->energyPoints;
	this->hitPoints += amount;
	std::cout << "[REPAIRED] " << this->name << " repair " << amount << " hit points. He had now " << this->hitPoints << " hit point." << std::endl;
}

bool ClapTrap::hasEnoughEnergy() 
{
	bool enoughEnergy;

	if (this->hitPoints <= 0)
	{
		std::cout << "[ERROR] " << this->name << " is dead, he can't do anything." << std::endl;
		return (false);
	}
	enoughEnergy = this->energyPoints > 0;
	if (!enoughEnergy)
		std::cout << "[ERROR] " << this->name << " has not enough energy ..." << std::endl;
	return (enoughEnergy);
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

void ClapTrap::setName(std::string name) 
{
	this->name = name;
}

int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}

std::ostream &operator<<(std::ostream &outputFile, ClapTrap const &ct)
{
	outputFile	<< ct.getName()<< " > "
				<< ct.getHitPoints() << " hp | "
				<< ct.getEnergyPoints() << " energy | "
				<< ct.getAttackDamage() << " attack damage";
	return outputFile;
}
