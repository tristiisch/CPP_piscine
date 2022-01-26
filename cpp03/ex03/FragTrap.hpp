/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/26 18:26:29 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define HIT_POINT 100
# define ENERGY_POINT 100
# define ATTACK_DAMAGE 30

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const& instance);
		FragTrap &operator=(FragTrap const &instance);
		~FragTrap();

		void highFivesGuys(void);
};

#endif
