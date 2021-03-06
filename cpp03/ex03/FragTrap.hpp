/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 22:06:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define HIT_POINT 100
# define ENERGY_POINT 100
# define ATTACK_DAMAGE 30

class FragTrap : public virtual ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const& instance);
		FragTrap &operator=(FragTrap const &instance);
		~FragTrap();

		void highFivesGuys(void);

	protected:
		static int hitPointsDefault;
		static int energyPointsDefault;
		static int attackDamageDefault;
};

#endif
