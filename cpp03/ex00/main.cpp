/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:13:46 by tglory            #+#    #+#             */
/*   Updated: 2022/01/26 01:45:37 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap foo("Foo");
	ClapTrap nameless;
	ClapTrap bar(foo);
	ClapTrap passive("Passive");

	bar.setName("Bar");
	
	foo.setAttackDamage(1);
	foo.setEnergyPoints(3);
	while (foo.getEnergyPoints())
	{
		foo.attack("Bar");
		bar.takeDamage(foo.getAttackDamage());
	}
	foo.attack("Bar");

	nameless.attack("the void");

	bar.beRepaired(5);

	std::cout << foo << std::endl;
	std::cout << nameless << std::endl;
	std::cout << bar << std::endl;
	std::cout << passive << std::endl;
	return (0);
}
