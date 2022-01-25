/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:27:59 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 17:58:59 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack() 
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
