/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:15:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 18:57:21 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	public:
		Weapon(std::string const &);
		void setType(std::string const &);
		std::string const &getType();

	private:
		std::string type;
};

#endif
