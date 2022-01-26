/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:13:55 by tglory            #+#    #+#             */
/*   Updated: 2022/01/26 14:28:00 by tglory           ###   ########lyon.fr   */
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
		void setHitPoints(int hitPoints);
		int getEnergyPoints() const;
		void setEnergyPoints(int energyPoints);
		int getAttackDamage() const;
		void setAttackDamage(int attackDamage);

	protected:
		bool hasEnoughEnergy();

	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

};

std::ostream &operator<<(std::ostream &outputFile, ClapTrap const &ct);

#endif
