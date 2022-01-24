/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:38:07 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 01:55:43 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include "randomChump.cpp"
# include "newZombie.cpp"

int main(void)
{
	Zombie *zombie;

	zombie = newZombie("Berber");
	zombie->announce();
	return 0;
}
