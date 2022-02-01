/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/02/01 16:07:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int FragTrap::hitPointsDefault = 100;
int FragTrap::energyPointsDefault = 100;
int FragTrap::attackDamageDefault = 30;

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Creates FragTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = this->hitPointsDefault;
	this->energyPoints = this->energyPointsDefault;
	this->attackDamage = this->attackDamageDefault;
}

FragTrap::FragTrap(std::string name)  : ClapTrap(name)
{
	std::cout << "Creates FragTrap '" << this->getName() << "'." << std::endl;
	this->hitPoints = this->hitPointsDefault;
	this->energyPoints = this->energyPointsDefault;
	this->attackDamage = this->attackDamageDefault;
}

FragTrap::FragTrap(FragTrap const &instance)  : ClapTrap(instance)
{
	std::cout << "Creates cloned FragTrap '" << this->getName() << "'." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &instance)
{
	this->name = instance.getName();
	this->hitPoints = instance.getHitPoints();
	this->energyPoints = instance.getEnergyPoints();
	this->attackDamage = instance.getAttackDamage();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " was destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "     _.-._" << std::endl;
	std::cout << "    | | | |_" << std::endl;
	std::cout << "    | | | | |" << std::endl;
	std::cout << "  _ |  '-._ |" << std::endl;
	std::cout << "  \\`\\`-.'-._;        Give me five !" << std::endl;
	std::cout << "   \\    '   |" << std::endl;
	std::cout << "    \\  .`  /" << std::endl;
	std::cout << "     |    |" << std::endl;
}
