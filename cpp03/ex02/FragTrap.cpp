/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:02:22 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 15:42:55 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Create FragTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(FT_HIT_POINT);
	this->setEnergyPoints(FT_ENERGY_POINT);
	this->setAttackDamage(FT_ATTACK_DAMAGE);
}

FragTrap::FragTrap(std::string name)  : ClapTrap(name)
{
	std::cout << "Create FragTrap '" << this->getName() << "'." << std::endl;
	this->setHitPoints(FT_HIT_POINT);
	this->setEnergyPoints(FT_ENERGY_POINT);
	this->setAttackDamage(FT_ATTACK_DAMAGE);
}

FragTrap::FragTrap(FragTrap const &instance)  : ClapTrap(instance)
{
	std::cout << "Create cloned FragTrap '" << this->getName() << "'." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &instance)
{
	this->setName(instance.getName());
	this->setHitPoints(instance.getHitPoints());
	this->setEnergyPoints(instance.getEnergyPoints());
	this->setAttackDamage(instance.getAttackDamage());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " was destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (!this->hasEnoughEnergy())
		return;
	std::cout << "     _.-._" << std::endl;
	std::cout << "    | | | |_" << std::endl;
	std::cout << "    | | | | |" << std::endl;
	std::cout << "  _ |  '-._ |" << std::endl;
	std::cout << "  \\`\\`-.'-._;        Give me five !" << std::endl;
	std::cout << "   \\    '   |" << std::endl;
	std::cout << "    \\  .`  /" << std::endl;
	std::cout << "     |    |" << std::endl;
}
