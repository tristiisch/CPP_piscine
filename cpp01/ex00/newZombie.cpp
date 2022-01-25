/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:35:47 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 17:28:22 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie;

	zombie = new Zombie(name);
	return (zombie);
}
