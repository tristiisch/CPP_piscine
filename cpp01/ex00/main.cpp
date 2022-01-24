/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:38:07 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 02:53:22 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	randomChump("Stack Zombie");

	zombie = newZombie("Heap Zombie");
	zombie->announce();
	delete zombie;

	return (0);
}
