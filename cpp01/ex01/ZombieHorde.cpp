/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 03:19:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 03:40:10 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	std::stringstream	ss;

	if (N <= 0)
		return (NULL);

	for (int i = 0; i < N; i++)
	{
		ss.str(std::string());
		ss << i;
		horde[i].setName(name + "_" + ss.str());
	}
	return (horde);
}