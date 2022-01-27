/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:21:55 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 18:17:14 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int size;

	size = 10;

	horde = zombieHorde(size, "Bob");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;

	return (0);
}
