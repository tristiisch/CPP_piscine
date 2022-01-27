/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:13:55 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 18:55:56 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& instance);
		ClapTrap &operator=(ClapTrap const &instance);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const; 
		void setName(std::string name);
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;

	protected:
		static int hitPointsDefault;
		static int energyPointsDefault;
		static int attackDamageDefault;

		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
		bool hasEnoughEnergy();

};

std::ostream &operator<<(std::ostream &outputFile, ClapTrap const &ct);

#endif
