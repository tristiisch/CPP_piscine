/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 14:34:29 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& instance);
		ScavTrap &operator=(ScavTrap const &instance);
		~ScavTrap();

		void guardGate();
};

#endif
