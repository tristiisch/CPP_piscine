/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:13:46 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 16:06:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap foo("Foo");
	DiamondTrap nameless;
	DiamondTrap bar(foo);
	DiamondTrap passive("Passive");

	bar.setName("Bar");
	std::cout << std::endl;

	while (foo.getEnergyPoints())
	{
		foo.attack("Bar");
		bar.takeDamage(foo.getAttackDamage());
	}
	foo.attack("Bar");
	std::cout << std::endl;

	nameless.attack("Bar");
	bar.takeDamage(nameless.getAttackDamage());
	std::cout << std::endl;

	bar.beRepaired(5);
	std::cout << std::endl;

	foo.beRepaired(1);
	std::cout << std::endl;

	nameless.attack("Foo");
	foo.takeDamage(nameless.getAttackDamage());
	std::cout << std::endl;

	nameless.attack("Foo");
	foo.takeDamage(nameless.getAttackDamage());
	std::cout << std::endl;

	nameless.highFivesGuys();
	std::cout << std::endl;

	bar.highFivesGuys();
	std::cout << std::endl;

	std::cout << foo << std::endl;
	std::cout << nameless << std::endl;
	std::cout << bar << std::endl;
	std::cout << passive << std::endl;
	std::cout << std::endl;
	return (0);
}
