/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:38:07 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 18:15:19 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	zombie = newZombie("Heap Zombie");
	zombie->announce();
	delete zombie;

	randomChump("Stack Zombie");

	return (0);
}
