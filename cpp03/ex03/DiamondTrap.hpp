/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:10 by tglory            #+#    #+#             */
/*   Updated: 2022/02/01 16:04:06 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& instance);
		DiamondTrap &operator=(DiamondTrap const &instance);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI();

		std::string getName() const;

	private:
		static int hitPointsDefault;
		static int energyPointsDefault;
		static int attackDamageDefault;

		std::string name;
};

#endif
