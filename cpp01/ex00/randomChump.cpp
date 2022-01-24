/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:35:43 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 01:55:42 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
# include "newZombie.cpp"

void randomChump(std::string name)
{
	Zombie *zombie = newZombie(name);
	zombie->announce();
}
